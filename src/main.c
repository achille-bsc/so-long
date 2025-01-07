/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 20:29:12 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	handle_keypress(int keycode, t_player *player)
{
	printf("Touche pressée : %d\n", keycode);
	if (keycode == 65307 || keycode == 113)
		exit(0);
	if (keycode == 65362)
	{
		move_up(player);
		player->moved = 1;
	}
	if (keycode == 65364)
	{
		move_down(player);
		player->moved = 1;
	}
	if (keycode == 65361)
	{
		move_left(player);
		player->moved = 1;
	}
	if (keycode == 65363)
	{
		move_right(player);
		player->moved = 1;
	}
	
	return (0);
}

char	*load_map(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (read_file(fd));
}

int	update(t_parameters *parameters)
{
	draw_map(parameters->window, parameters->map, parameters->player);
	return (0);
}

int	main(int argc, char **argv)
{
	void			*mlx;
	void			*win;
	t_window		*window;
	char			*map;
	t_player		*player;
	t_parameters	*parameters;

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
	map = load_map(map);
	player = init_player(map);
	parameters = malloc(sizeof(t_parameters));
	parameters->window = window;
	parameters->map = map;
	parameters->player = player;
	draw_map(window, map, player);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_key_hook(win, handle_keypress, player);
	mlx_loop_hook(mlx, update, parameters);
	mlx_loop(mlx);
	return (0);
}
