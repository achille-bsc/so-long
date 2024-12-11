/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2024/12/11 17:31:57 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int close_window(void *param)
{
    (void)param;
    exit(0);
}

int handle_keypress(int keycode, void *param)
{
    (void)param;
    printf("Touche pressée : %d\n", keycode);
    if (keycode == 65307) // 65307 est le code de la touche ESC sous Linux
        exit(0); // Quitter le programme si ESC est pressée

    return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1080, 720, "So Long");
	if (!win)
		return (1);
	
	img = mlx_xpm_file_to_image(mlx, "./textures/rene.xpm", &width, &height);
	if (!img)
		return (1);

	mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_hook(win, 17, 0, close_window, NULL);

	// Lier la fonction handle_keypress à un événement de touche pressée
    mlx_key_hook(win, handle_keypress, NULL);

	mlx_loop(mlx);
	return (0);
}
