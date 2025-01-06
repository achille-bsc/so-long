/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/06 10:41:34 by abosc            ###   ########.fr       */
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
	void		*mlx;
	void		*win;
	// int			width;
	// int			height;
	t_window	*window;

	window = malloc(sizeof(t_window));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1080, 720, "So Long");
	if (!win)
		return (1);

	window->mlx = mlx;
	window->win = win;
	ft_printf("000\n");
	draw_map(window, "../maps/map_simple.bers");
	ft_printf("999\n");
    mlx_hook(win, 17, 0, close_window, NULL);

    mlx_key_hook(win, handle_keypress, NULL);

	mlx_loop(mlx);
	return (0);
}
