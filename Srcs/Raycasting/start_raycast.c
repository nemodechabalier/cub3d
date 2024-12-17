/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:18:29 by clmanouk          #+#    #+#             */
/*   Updated: 2024/12/16 17:43:46 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	key_release(int keycode, t_map *map)
{
	if (keycode == 65307)
		close_window(map);
	else if (keycode == 'w' || keycode == 'W' || (keycode == 65362))
		map->game->keys[key_w] = false;
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		map->game->keys[key_s] = false;
	else if (keycode == 65361)
		map->game->keys[key_left] = false;
	else if (keycode == 65363)
		map->game->keys[key_right] = false;
	else if ((keycode == 'a' || keycode == 'A'))
		map->game->keys[key_a] = false;
	else if ((keycode == 'd' || keycode == 'D'))
		map->game->keys[key_d] = false;
	else
		return (FAIL);
	return (SUCCESS);
}

int	init_game(t_map *map, t_file *file)
{
	t_texture	*texture;

	texture = texture_constructor(file);
	if (!texture)
		return (FAIL);
	map->game->text = ft_init_texture(map->game, texture);
	if (!map->game->text)
		return (map->game->text = texture, file_dest(file, 1),
			close_window(map), FAIL);
	file_dest(file, 1);
	mlx_loop_hook(map->game->mlx, &render, map);
	mlx_hook(map->game->mlx_win, KeyPress, KeyPressMask, &move_player, map);
	mlx_hook(map->game->mlx_win, KeyRelease, KeyReleaseMask, &key_release, map);
	mlx_hook(map->game->mlx_win, DestroyNotify, NoEventMask, close_window, map);
	mlx_loop(map->game->mlx);
	close_window(map);
	return (SUCCESS);
}

void	new_player(t_map *map)
{
	int		i;
	int		j;
	char	c;

	int (x) = (int)map->game->player->pos_x;
	int (y) = (int)map->game->player->pos_y;
	i = 0;
	j = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (ft_strchr("WNSE", map->grid[i][j]))
			{
				c = map->grid[i][j];
				map->grid[i][j] = '0';
				map->grid[y][x] = c;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	choose_key(t_map *map)
{
	t_player	*player;

	player = map->game->player;
	if (map->img_ptr)
		mlx_destroy_image(map->game->mlx, map->img_ptr);
	if (map->game->keys[key_w] == true)
		move_player_dir(map, player, 1);
	if (map->game->keys[key_s] == true)
		move_player_dir(map, player, 0);
	if (map->game->keys[key_left] == true)
		ft_rotate_player(player, -0.01f, player->table);
	if (map->game->keys[key_right] == true)
		ft_rotate_player(player, 0.01f, player->table);
	if (map->game->keys[key_a] == true)
		move_player_ad(map, player, 1);
	if (map->game->keys[key_d] == true)
		move_player_ad(map, player, 0);
}

int	render(t_map *map)
{
	choose_key(map);
	map->img_ptr = mlx_new_image(map->game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!map->img_ptr)
		return (1);
	map->addr = mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel,
			&map->line_length, &map->endian);
	if (!map->game->player)
		return (1);
	draw_game(map);
	new_player(map);
	draw_minimap(map, 150);
	mlx_put_image_to_window(map->game->mlx, map->game->mlx_win, map->img_ptr, 0,
		0);
	return (0);
}
