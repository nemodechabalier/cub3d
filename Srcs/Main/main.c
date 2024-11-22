/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clmanouk <clmanouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:22 by clmanouk          #+#    #+#             */
/*   Updated: 2024/11/22 12:08:56 by clmanouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_file	*file;

	file = NULL;
	map = NULL;
	if (ac != 2)
		return (printf("wrong nb args\n"), -1);
	file = take_file(av[1]);
	map = return_value_file(file->map);
	init_game(map);
	return (0);
}

//#include "../../mlx_linux/mlx.h"
//#include <stdio.h>
//#include <stdlib.h>

// typedef struct s_img
//{
//	void *img_ptr; // Pointeur de l'image
//	char *addr;    // Adresse des pixels
//	int bpp;       // Bits par pixel
//	int line_len;  // Longueur d'une ligne en octets
//	int endian;    // Ordre des octets (0 = petit endian, 1 = gros endian)
//}	t_img;

// int	main(void)
//{
//	int		x;
//	int		y;
//	char	*pixel;

//	void *mlx; // Instance MiniLibX
//	void *win; // Fenêtre MiniLibX
//	t_img img; // Structure pour l'image
//	// Initialiser MiniLibX
//	mlx = mlx_init();
//	if (!mlx)
//	{
//		fprintf(stderr, "Error: MLX initialization failed\n");
//		return (EXIT_FAILURE);
//	}
//	// Créer une fenêtre
//	win = mlx_new_window(mlx, 800, 600, "Cub3D - Image Example");
//	if (!win)
//	{
//		fprintf(stderr, "Error: Window creation failed\n");
//		return (EXIT_FAILURE);
//	}
//	// Créer une image
//	img.img_ptr = mlx_new_image(mlx, 800, 600);
//	if (!img.img_ptr)
//	{
//		fprintf(stderr, "Error: Image creation failed\n");
//		return (EXIT_FAILURE);
//	}
//	// Récupérer les informations sur l'image
//	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len,
//			&img.endian);
//	// Dessiner un pixel rouge (juste un exemple)
//	x = 400;
//	y = 300;
//	int color = 0x00FF0000; // Rouge en hexadécimal (ARGB)
//	pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
//	*(unsigned int *)pixel = color;
//	// Afficher l'image dans la fenêtre
//	mlx_put_image_to_window(mlx, win, img.img_ptr, 0, 0);
//	// Lancer la boucle d'événements
//	mlx_loop(mlx);
//	return (EXIT_SUCCESS);
//}
