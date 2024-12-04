/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:50:16 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/04 11:30:17 by clmanouk         ###   ########.fr       */
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

	texture = map->game->text;
	if (player->dda->side == 0)
		wall_x = player->pos_y + player->dda->perp_wall_dist
			* player->dda->ray_dir_y;
	else
		wall_x = player->pos_x + player->dda->perp_wall_dist
			* player->dda->ray_dir_x;
	wall_x -= floor(wall_x);
	texture_x = (wall_x * (texWidth));
	if (player->dda->side == 0 && player->dda->ray_dir_x > 0)
		texture_x = texWidth - texture_x - 1;
	if (player->dda->side == 1 && player->dda->ray_dir_y < 0)
		texture_x = texWidth - texture_x - 1;
	line_height = (int)(SCREEN_HEIGHT / map->game->player->dda->perp_wall_dist
			* 0.2);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	step = 1.0 * texHeight / line_height;
	texPos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		texture_y = (int)texPos & (texHeight - 1); // mask with (texHeight- 1) in case of overflow
		texPos += step;
		int color = *(int *)(texture->addr + (texture_y * texture->line_length + texture->bits_per_pixel));
		draw_wall(map, color, x, y);
		y++;
	}
}

t_texture	*ft_init_texture(t_game *game, char *path, t_texture *texture)
{
	(void)path;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free(game), NULL);
	game->mlx_win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"CUB3D");
	if (!game->mlx_win)
		return (free(game), NULL);
	texture->data = 0;
	texture->height = texHeight;
	texture->width = texWidth;
	texture->img_ptr = mlx_xpm_file_to_image(game->mlx, path, &texture->width,
			&texture->height);
	texture->addr = mlx_get_data_addr(texture->img_ptr,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	texture->img_ptr = NULL;
	return (texture);
}
