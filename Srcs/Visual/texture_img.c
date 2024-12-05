/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:50:16 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/05 19:49:28 by clmanouk         ###   ########.fr       */
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
	int			sub_texture_x;

	// int			textNum = map->grid[player->dda->map_x][player->dda->map_y]- 1;
	texture = map->game->text;
	tex_index = (player->dda->side == 0) ? 0 : 1;
	if (player->dda->side == 0)
		wall_x = player->pos_y + player->dda->perp_wall_dist
			* player->dda->ray_dir_y;
	else
		wall_x = player->pos_x + player->dda->perp_wall_dist
			* player->dda->ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (int)(wall_x * (texWidth));
	line_height = (int)(SCREEN_HEIGHT / map->game->player->dda->perp_wall_dist
			* 0.2);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	step = 1.0 * texHeight / line_height;
	texPos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2);
	y = draw_start;
	while (y < draw_end)
	{
		texture_y = (int)texPos & (texHeight - 1);
		// texture_y = (int)((texPos * texture->height) / line_height);
		texPos += step;
		sub_texture_x = (int)(wall_x * texture->width) % texture->width;
		color = (int *)(texture->addr[tex_index] + (texture_y
					* texture->line_length + sub_texture_x
					* (texture->bits_per_pixel / 8)));
		draw_wall(map, color, x, y);
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
	texture->path[0] = "greystone.xpm";
	texture->path[1] = "redbrick.xpm";
	while (i < 2)
	{
		texture->img_ptr[i] = mlx_xpm_file_to_image(game->mlx, texture->path[i],
				&texture->width, &texture->height);
		if (!texture->img_ptr[i])
			return (printf("Error init texture\n"), NULL);
		texture->addr[i] = mlx_get_data_addr(texture->img_ptr[i],
				&texture->bits_per_pixel, &texture->line_length,
				&texture->endian);
		i++;
	}
	return (texture);
}
