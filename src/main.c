/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/22 00:45:41 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_window(t_parameters *param)
{
	if (param)
    {
        if (param->map)
            free(param->map);
        if (param->player)
            free(param->player);
        if (param->window)
        {
            if (param->window->mlx && param->window->win)
                mlx_destroy_window(param->window->mlx, param->window->win);
            if (param->window->mlx)
            {
                mlx_destroy_display(param->window->mlx);
                free(param->window->mlx);
            }
            free(param->window);
        }
        free(param);
    }
    exit(0);
}

int	handle_keypress(int keycode, t_parameters *params)
{
	if (keycode == 65307 || keycode == 113)
		close_window(params);
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

int	update(t_parameters *parameters)
{
	usleep(1000000 / FPS);
	if (parameters->player->moved)
	{
		draw_map(parameters->map, parameters->player, parameters);
		parameters->player->moved = 0;
		parameters->player->steps++;
		ft_printf("Steps: %d\n", parameters->player->steps);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	void			*mlx;
	char			*map;
	t_parameters	*parameters;

	parameters = init_parameters();
	mlx = create_mlx();
	map = get_map(argc, argv);
	map = load_map(map);
	parameters->map = map;
	parameters->window = ft_calloc(1, sizeof(t_window));
	parameters->window->mlx = mlx;
	parameters->collectibles_count = load_collectibles(parameters->map);
	parameters->player = init_player(parameters);
	parameters->img_count = 0;

	if (!validate_map(parameters->map, get_map_width(parameters->map),
			get_map_height(parameters->map)))
	{
		ft_printf("Invalid map\n");
		exit(1);
	}
	parameters->window->win = create_window(mlx, parameters);
	draw_map(parameters->map, parameters->player, parameters);
	mlx_hook(parameters->window->win, EVENT_CLOSE, 0, close_window, parameters);
	mlx_key_hook(parameters->window->win, handle_keypress, parameters);
	return (mlx_loop_hook(mlx, update, parameters), mlx_loop(mlx), 0);
}
