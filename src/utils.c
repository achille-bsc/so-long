/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achillebosc <achillebosc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 03:17:03 by abosc             #+#    #+#             */
/*   Updated: 2025/01/12 15:11:40 by achillebosc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*get_map(int argc, char **argv)
{
	char	*map;

	map = "./maps/map_simple.ber";
	if (argc != 1)
		map = argv[1];
	return (map);
}

void	*create_window(void *mlx)
{
	void	*win;

	win = mlx_new_window(mlx, 1080, 720, "So Long");
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
		exit(0);
	return (parameters);
}
char	*load_map(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (read_file(fd));
}