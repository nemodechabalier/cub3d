/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:47:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/12 19:31:38 by nde-chab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Includes/cub3d.h"

/*
Initialisation de side_dist_x et side_dist_y:

side_dist_x et side_dist_y représentent la distance que le rayon doit parcourir pour atteindre la prochaine intersection avec un bord de cellule dans la direction x et y respectivement.
Le calcul dépend de la direction du rayon, représentée par les signes de ray_dir_x et ray_dir_y.
Si ray_dir_x est négatif, le rayon se déplace vers la gauche, donc la distance à parcourir est player->x - dda->map_x. Sinon, la distance est dda->map_x + 1.0 - player->x.
De même pour ray_dir_y, si elle est négative, la distance est player->y - dda->map_y, sinon c'est dda->map_y + 1.0 - player->y.
Ces distances sont ensuite multipliées par dda->delta_dist_x et dda->delta_dist_y respectivement, pour obtenir les distances réelles à parcourir.


Initialisation de delta_dist_x et delta_dist_y:

delta_dist_x et delta_dist_y représentent la distance que le rayon doit parcourir pour passer d'une cellule à la cellule suivante dans la direction x et y respectivement.
Cette distance est calculée en fonction de l'inverse des composantes du vecteur de direction du rayon (ray_dir_x et ray_dir_y).
Si une des composantes est égale à 0, cela signifie que le rayon se déplace parallèlement à l'axe correspondant. Dans ce cas, on initialise la distance delta à une très grande valeur (1e30) pour éviter les divisions par 0.
Sinon, on calcule la valeur absolue de l'inverse de la composante correspondante (fabs(1 / ray_dir_x) et fabs(1 / ray_dir_y)).

*/

void	init_dda(t_dda *dda, t_calcul_table *table, t_player *player)
{
	(void)table;
	(void)table;
	dda->map_x = player->x;
	dda->map_y = player->y;
	dda->ray_dir_x = cos(player->angle * DEG_TO_RAD);
	dda->ray_dir_y = sin(player->angle * DEG_TO_RAD);
	/*
	manque 
	side_distance 
	delat_distance
	step_x = what direction to step in x or y-direction (either +1 or -1) selon dx dy
	*/
	dda->hit = 0;
	dda->perp_wall_dist = 0;
	//dda->player_dir = &player->angle;
	dda->player = player;
}