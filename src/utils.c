/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:17:03 by abosc             #+#    #+#             */
/*   Updated: 2025/01/24 00:01:05 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*get_map(int argc, char **argv, void *mlx, t_parameters *params)
{
	char	*map;

	map = "./maps/map_simple.ber";
	if (argc == 2)
		map = argv[1];
	if (ft_strncmp(map + ft_strlen(map) - 4, ".ber", 4) != 0 || argc > 2)
	{
		params->window = ft_calloc(1, sizeof(t_window));
		params->window->mlx = mlx;
		close_window(params, 0);
	}
	return (map);
}

void	*create_window(void *mlx, t_parameters *params)
{
	void	*win;
	int		width;
	int		height;

	width = get_map_width(params->map) * 32;
	height = get_map_height(params->map) * 32;
	win = mlx_new_window(mlx, width, height, "So Long");
	if (!win)
		exit(1);
	return (win);
}

void	*create_mlx(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		exit(1);
	return (mlx);
}

t_parameters	*init_parameters(void)
{
	t_parameters	*parameters;

	parameters = ft_calloc(1, sizeof(t_parameters));
	if (!parameters)
		exit(1);
	return (parameters);
}

char	*load_map(char *map, void *mlx, t_parameters *params)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		params->window = ft_calloc(1, sizeof(t_window));
		params->window->mlx = mlx;
		close_window(params, 0);
	}
	return (read_file(fd));
}
