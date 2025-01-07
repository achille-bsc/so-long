/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 16:35:08 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	printf("Touche pressée : %d\n", keycode);
	if (keycode == 65307 || keycode == 113)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	void		*mlx;
	void		*win;
	t_window	*window;
	char		*map;
	t_player	*player;

	map = "./maps/map_simple.ber";
	if (argc != 1)
		map = argv[1];
	window = malloc(sizeof(t_window));
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1080, 720, "So Long");
	if (!win)
		return (1);
	window->mlx = mlx;
	window->win = win;
	player = calcul_player();
	draw_map(window, map, player);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_key_hook(win, handle_keypress, NULL);
	mlx_loop(mlx);
	return (0);
}
