/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:11:00 by clmanouk          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2024/11/12 18:25:40 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

/*
+---------------+        +---------------+
|   Initialiser  |       |   Initialiser  |
| - Position     |       | - Allouer      |
| - Angle joueur |       |   tables       |
+---------------+        | - Remplir      |
		|                |   sin, cos, tan|
		v                | - Calculer     |
+---------------+        |   angles FOV   |
|    Boucle      |        +---------------+
| - Calculer     |                |
|   angle rayon  |                v
| - Obtenir      |        +---------------+
|   direction    |        |    Boucle     |
|   (dx, dy)     |        | - Calculer    |
|   depuis tables|        |   prochaines  |
| - Utiliser DDA |        |  intersections|
|   avec dx, dy  |        | - Avancer     |
+---------------+         |  vers la plus |
						  |    proche     |
						  |- Vérifier mur |
						  +---------------+
									|
									v
							+---------------+
							|   Calculer    |
							|   distance    |
							|   perpendicu- |
							|   laire       |
							+---------------+

*/

t_calcul_table	*init_calcul(t_player *player)
{
	int				i;
	t_calcul_table	*table;
	float			angle;

	i = 0;
	table = malloc(sizeof(t_calcul_table));
	if (!table)
		return ;
	table->cos = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->cos)
		return ;
	table->sin = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->sin)
		return ;
	table->fish_eyes = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->fish_eyes)
		return ;
	table->tang = malloc(sizeof(float) * TABLE_SIZE);
	if (!table->tang)
		return ;
	table->calcul_angle_fov = malloc(sizeof(float) * player->fov);
	if (!table->calcul_angle_fov)
		return ;
	while (i < TABLE_SIZE)
	{
		angle = (i + player->angle) * DEG_TO_RAD;
		table->sin[i] = sin(angle);
		table->cos[i] = cos(angle);
		table->tang[i] = tan(angle);
		table->calcul_angle_fov[i] = cos(angle);
		i++;
	}
	//+ calcul des angles pour chaque rayon du fov et converti la position x en angle ds le fov
	return (table);
}

void	init_player(t_player *player, t_calcul_table *table, t_map *map)
{
	// a initialiser
	player->x = 0;
	player->y = 0;
	player->angle = atan2(player->x, player->y) * RAD_TO_DEG;
	player->fov = 60 + player->angle / 2; // parametre a revoir;
	player->player_dir = NULL;
	player->table = table;
}
=======
/*   Updated: 2024/11/12 17:24:16 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../../Includes/cub3d.h"

//t_img	init_data(void)
//{
//	t_img	*data;

//	data = malloc(sizeof(t_img));
//	if (!data)
//		return ;
//	data->height = 0;
//	data->length = 0;
//}

//t_calcul_table	init_calcul(int width_window, float fov)
//{
//	t_calcul_table	*table;

//	table = malloc(sizeof(t_calcul_table));
//	if (!table)
//		return ;
//	table->cos = malloc(sizeof(float) * TABLE_SIZE);
//	if (!table->cos)
//		return ;
//	table->sin = malloc(sizeof(float) * TABLE_SIZE);
//	if (!table->cos)
//		return ;
//	table->fish_eyes = malloc(sizeof(float) * TABLE_SIZE);
//	if (!table->fish_eyes)
//		return ;
//	table->tang = malloc(sizeof(float) * TABLE_SIZE);
//	if (!table->tang)
//		return ;
//	table->calcul_angle_fov = malloc(sizeof(float) * width_window);
//	if (!table->calcul_angle_fov)
//		return ;
//}
>>>>>>> Stashed changes
