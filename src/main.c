/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/09 18:12:04 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_window(t_parameters *param)
{
	free(param->map);
	free(param->player);
	mlx_destroy_window(param->window->mlx, param->window->win);
	mlx_destroy_display(param->window->mlx);
	free(param);
	exit(0);
}

int	handle_keypress(int keycode, t_parameters *params)
{
	// printf("Touche pressée : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
	{
		move_up(params->player, params);
		params->player->moved = 1;
	}
	if (keycode == 65364)
	{
		move_down(params->player, params);
		params->player->moved = 1;
	}
	if (keycode == 65361)
	{
		move_left(params->player, params);
		params->player->moved = 1;
	}
	if (keycode == 65363)
	{
		move_right(params->player, params);
		params->player->moved = 1;
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
	if (parameters->player->moved)
	{
		draw_map(parameters->window, parameters->map, parameters->player);
		parameters->player->moved = 0;
	}
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
	window = ft_calloc(1, sizeof(t_window));
	mlx = mlx_init();
	if (!mlx)
		return (0);
	win = mlx_new_window(mlx, 1080, 720, "So Long");
	if (!win)
		return (1);
	window->mlx = mlx;
	window->win = win;
	map = load_map(map);
	player = init_player(map);
	parameters = ft_calloc(1, sizeof(t_parameters));
	parameters->window = window;
	parameters->map = map;
	parameters->player = player;
	draw_map(window, map, player);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_hook(win, 2, KeyPressMask, handle_keypress, parameters);
	mlx_loop_hook(mlx, update, parameters);
	mlx_loop(mlx);
	return (0);
}
