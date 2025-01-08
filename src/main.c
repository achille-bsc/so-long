/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achillebosc <achillebosc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/08 14:21:36 by achillebosc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

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

static t_parameters	*init_game(int argc, char **argv, t_window **window)
{
	t_parameters	*parameters;
	char			*map;

	map = "./maps/map_simple.ber";
	if (argc != 1)
		map = argv[1];
	*window = malloc(sizeof(t_window));
	if (!*window)
		return (NULL);
	(*window)->mlx = mlx_init();
	(*window)->win = mlx_new_window((*window)->mlx, 1080, 720, "So Long");
	if (!(*window)->win)
		return (NULL);
	map = load_map(map);
	parameters = malloc(sizeof(t_parameters));
	if (!parameters)
		return (NULL);
	parameters->window = *window;
	parameters->map = map;
	parameters->player = init_player(map);
	return (parameters);
}

int	main(int argc, char **argv)
{
	void			*mlx;
	void			*win;
	t_window		*window;
	t_parameters	*parameters;

	parameters = init_game(argc, argv, &window);
	if (!parameters)
		return (1);
	draw_map(window, parameters->map, parameters->player);
	mlx_hook(window->win, EVENT_CLOSE, MASK_NO_EVENT, exit, NULL);
	mlx_key_hook(window->win, handle_keypress, parameters->player);
	mlx_loop_hook(window->mlx, update, parameters);
	mlx_loop(window->mlx);
	return (0);
}
