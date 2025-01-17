/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:50:16 by clmanouk          #+#    #+#             */
/*   Updated: 2025/01/15 13:37:08 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

/*
floor calcul l'arrondie entier inferieur
*/

void	choose_texture(t_player *player, t_texture *tex)
{
	if (player->dda->side == 0)
	{
		if (player->dda->ray_dir_x > 0)
			tex->tex_index = 1;
		else
			tex->tex_index = 0;
		tex->wall_x = player->pos_y + player->dda->perp_wall_dist
			* player->dda->ray_dir_y;
	}
	else
	{
		if (player->dda->ray_dir_y > 0)
			tex->tex_index = 2;
		else
			tex->tex_index = 3;
		tex->wall_x = player->pos_x + player->dda->perp_wall_dist
			* player->dda->ray_dir_x;
	}
	tex->wall_x -= floor(tex->wall_x);
	if ((player->dda->side == 0 && player->dda->ray_dir_x < 0)
		|| (player->dda->side == 1 && player->dda->ray_dir_y > 0))
		tex->wall_x = 1 - tex->wall_x;
}

void	draw_texture(t_map *map, int draw_end, int x, int draw_start)
{
	int			y;
	int			*color;
	t_texture	*texture;

	texture = map->game->text;
	y = draw_start;
	while (y < draw_end)
	{
		texture->texture_y = (int)texture->texpos % TEXHEIGHT;
		color = (int *)(texture->addr[texture->tex_index] + texture->texture_y
				* texture->line_length + texture->texture_x
				* (texture->bits_per_pixel / 8));
		draw_wall(map, color, x, y);
		texture->texpos += texture->step;
		y++;
	}
}

void	get_texture_position(t_map *map, t_player *player, int x)
{
	t_texture	*tex;
	int			draw_start;
	int			draw_end;

	tex = map->game->text;
	choose_texture(player, tex);
	if (tex->wall_x < 0)
		tex->wall_x = 0;
	if (tex->wall_x > 1)
		tex->wall_x = 1;
	tex->texture_x = (int)(tex->wall_x * (double)TEXWIDTH) % TEXWIDTH;
	tex->line_height = (int)(SCREEN_HEIGHT
			/ map->game->player->dda->perp_wall_dist * 0.99);
	draw_start = -tex->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = tex->line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end > SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT;
	tex->step = 1.0 * TEXHEIGHT / tex->line_height;
	tex->texpos = (draw_start - SCREEN_HEIGHT / 2 + tex->line_height / 2)
		* tex->step;
	draw_texture(map, draw_end, x, draw_start);
}

t_texture	*ft_init_texture(t_game *game, t_texture *texture)
{
	int (i) = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), NULL);
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"CUB3D");
	if (!game->mlx_win)
		return (free(game), NULL);
	texture->height = TEXHEIGHT;
	texture->width = TEXWIDTH;
	while (i < 4)
	{
		texture->img_ptr[i] = mlx_xpm_file_to_image(game->mlx, texture->path[i]
				+ 3, &texture->width, &texture->height);
		if (!texture->img_ptr[i] || texture->width != TEXWIDTH
			|| texture->height != TEXHEIGHT)
			return (printf("Error\nloading texture %s\n", texture->path[i]),
				NULL);
		texture->addr[i] = mlx_get_data_addr(texture->img_ptr[i],
				&texture->bits_per_pixel, &texture->line_length,
				&texture->endian);
		i++;
	}
	return (texture);
}
