/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:50:16 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/12 13:36:53 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

/*
floor calcul l'arrondie entier inferieur
*/

void	get_texture_position(t_map *map, t_player *player, int x)
{
	int			texture_x;
	int			texture_y;
	int			line_height;
	double		wall_x;
	t_texture	*texture;
	int			y;
	int			draw_start;
	int			draw_end;
	double		step;
	double		texPos;
	int			*color;
	int			tex_index;
	//int			sub_texture_x;

	texture = map->game->text;
	if (player->dda->side == 0)
	{
		if (player->dda->ray_dir_x > 0)
			tex_index = 1;
		else
			tex_index = 0;
		wall_x = player->pos_y + player->dda->perp_wall_dist
			* player->dda->ray_dir_y;
		wall_x -= floor(wall_x);
	}
	else
	{
		if (player->dda->ray_dir_y > 0)
			tex_index = 2;
		else
			tex_index = 3;
		wall_x = player->pos_x + player->dda->perp_wall_dist
			* player->dda->ray_dir_x;
		wall_x -= floor(wall_x);
	}
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (double)texWidth) % texWidth;
	line_height = (int)(SCREEN_HEIGHT / map->game->player->dda->perp_wall_dist
		* 0.8);
	printf("line height = %d\n\n", line_height);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end > SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT;
	step = 1.0 * texHeight / line_height;
	texPos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		texture_y = (int)texPos & (texHeight - 1);
		//sub_texture_x = (int)(wall_x * texWidth) % texture->width;
		color = (int *)(texture->addr[tex_index] + texture_y
				* texture->line_length + texture_x * (texture->bits_per_pixel
					/ 8));
		draw_wall(map, color, x, y);
		texPos += step;
		y++;
	}
}

t_texture	*ft_init_texture(t_game *game, t_texture *texture)
{
	int(i) = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), NULL);
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"CUB3D");
	if (!game->mlx_win)
		return (free(game), NULL);
	texture->height = texHeight;
	texture->width = texWidth;
	while (i < 4)
	{
		texture->img_ptr[i] = mlx_xpm_file_to_image(game->mlx, texture->path[i] + 3,
				&texture->width, &texture->height);
		if (!texture->img_ptr[i])
			return (printf("Error loading texture %s\n", texture->path[i]),
				NULL);
		texture->addr[i] = mlx_get_data_addr(texture->img_ptr[i],
				&texture->bits_per_pixel, &texture->line_length,
				&texture->endian);
		i++;
	}
	return (texture);
}
