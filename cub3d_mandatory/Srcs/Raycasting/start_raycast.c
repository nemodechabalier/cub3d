/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:18:29 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/10 18:12:52 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	init_game(t_map *map, t_file *file)
{
	t_texture	*texture;

	texture = texture_constructor(file);
	if (!texture)
		return (FAIL);
	map->game->text = ft_init_texture(map->game, texture);
	if (!map->game->text)
		return (FAIL);
	mlx_loop_hook(map->game->mlx, &render, map);
	mlx_hook(map->game->mlx_win, 2, 1, &move_player, map);
	mlx_hook(map->game->mlx_win, 17, 0, close_window, map);
	// mlx_mouse_hook(map->game->mlx_win, appelle_func_pour_souris, map);
	mlx_loop(map->game->mlx);
	close_window(map);
	return (SUCCESS);
}

int	render(t_map *map)
{
	if (map->img_ptr)
		mlx_destroy_image(map->game->mlx, map->img_ptr);
	map->img_ptr = mlx_new_image(map->game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!map->img_ptr)
		return (1);
	map->addr = mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel,
			&map->line_length, &map->endian);
	if (!map->game->player)
		return (1);
	draw_game(map);
	draw_minimap(map, 150);
	mlx_put_image_to_window(map->game->mlx, map->game->mlx_win, map->img_ptr, 0,
		0);
	return (0);
}
