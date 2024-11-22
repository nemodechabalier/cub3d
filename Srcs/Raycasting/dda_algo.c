/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:46:11 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/22 18:53:52 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	calcul_ray_dir(t_player *player, int x)
{
	float	camera_x;

	camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
	printf("Camera_x %f\nDir_x %f\nPlane_x %f\n", camera_x, player->dir_x, player->dir_y);
	player->dda->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	player->dda->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	if (player->dda->ray_dir_x == 0)
		player->dda->delta_dist_x = 1e30;
	else
		player->dda->delta_dist_x = fabs(1 / player->dda->ray_dir_x);
	if (player->dda->ray_dir_y == 0)
		player->dda->delta_dist_y = 1e30;
	else
		player->dda->delta_dist_y = fabs(1 / player->dda->ray_dir_y);
}

void	init_dda(t_player *player)
{
	player->dda->map_x = (int)player->pos_x;
	player->dda->map_y = (int)player->pos_y;
	printf("ray_dir_x =%f, ray_dir_y = %f\n", player->dda->ray_dir_x,
		player->dda->ray_dir_y);
	if (player->dda->ray_dir_x < 0)
	{
		player->dda->step_x = -1;
		player->dda->side_dist_x = (player->pos_x - player->dda->map_x)
			* player->dda->delta_dist_x;
	}
	else
	{
		player->dda->step_x = 1;
		player->dda->side_dist_x = (player->dda->map_x + 1.0 - player->pos_x)
			* player->dda->delta_dist_x;
	}
	if (player->dda->ray_dir_y < 0)
	{
		player->dda->step_y = -1;
		player->dda->side_dist_y = (player->pos_y - player->dda->map_y)
			* player->dda->delta_dist_y;
	}
	else
	{
		player->dda->step_y = 1;
		player->dda->side_dist_y = (player->dda->map_y + 1.0 - player->pos_y)
			* player->dda->delta_dist_y;
	}
}

void	draw_wall(t_map *map, int x, int side)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	int	y;
	(void)side;

	line_height = (int)(SCREEN_HEIGHT / map->game->player->dda->perp_wall_dist);
	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
	if (draw_end >= SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT - 1;
	color = 0x0080FF;
	y = draw_start;
	while (y < draw_end)
	{
		mlx_pixel_put(map->game->mlx, map->game->mlx_win, x, y, color);
		y++;
	}
}

int	start_algo_dda(t_map *map, t_player *player, int x)
{
	int	side;

	calcul_ray_dir(player, x);
	init_dda(player);
	if (player->dda == NULL)
		return (1);
	player->dda->hit = 0;
	while (player->dda->hit == 0)
	{
		if (player->dda->side_dist_x < player->dda->side_dist_y)
		{
			player->dda->side_dist_x += player->dda->delta_dist_x;
			player->dda->map_x += player->dda->step_x;
			side = 0;
		}
		else
		{
			player->dda->side_dist_y += player->dda->delta_dist_y;
			player->dda->map_y += player->dda->step_y;
			side = 1;
		}
		if (player->dda->map_x < 0 || player->dda->map_x >= map->length
			|| player->dda->map_y < 0 || player->dda->map_y >= map->height)
		{
			printf("Error bundary map\n");
			break ;
		}
		if (map->grid[player->dda->map_x][player->dda->map_y] > 0)
		{
			player->dda->hit = 1;
			break ;
		}
	}
	if (side == 0)
		player->dda->perp_wall_dist = (player->dda->side_dist_x
				- player->dda->delta_dist_x);
	else
		player->dda->perp_wall_dist = (player->dda->side_dist_y
				- player->dda->delta_dist_y);
	printf("SIde_dist_x %f\nDelta_side_x %f\n", player->dda->side_dist_x, player->dda->delta_dist_x);
	printf("SIde_dist_y %f\nDelta_side_y %f\n", player->dda->side_dist_y, player->dda->delta_dist_y);
	draw_background(map, side);
	return (0);
}

int	render(t_map *map)
{
	int	x;

	x = 0;
	map->img_ptr = mlx_new_image(map->game->mlx, map->length, map->height);
	if (!map->img_ptr)
		return (1);
	if (!map->game->player)
		return (1);
	while (x < SCREEN_WIDTH)
	{
		start_algo_dda(map, map->game->player, x);
		x++;
	}
	mlx_put_image_to_window(map->game->mlx, map->game->mlx_win, map->img_ptr, 0,
		0);
	mlx_destroy_image(map->game->mlx, map->img_ptr);
	return (0);
}
