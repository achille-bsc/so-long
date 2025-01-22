/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:53:19 by achillebosc       #+#    #+#             */
/*   Updated: 2025/01/22 22:15:21 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_pos	search_start(t_parameters *params)
{
	t_pos	pos;
	int		i;

	i = 0;
	while (params->map[i])
	{
		if (params->map[i] == 'P')
			return (pos);
		i++;
		pos.x++;
		if (params->map[i] == '\n')
		{
			pos.y++;
			pos.x = 0;
		}
	}
	return (pos);
}

int	flood_fill(char **map, t_pos *coord, int *exit, int *collectibles)
{
	if (check_position(map, coord, exit, collectibles))
		return (1);
	if (process_neighbors(map, coord, exit, collectibles))
		return (1);
	return (0);
}

int	validate_map(char *map, int width, int height)
{
	t_map_validation	validation;
	char				**new_map;
	int					lines;

	validation = (t_map_validation){(t_pos){-1, -1}, 0, 0, width, height};
	new_map = ft_split(map, '\n');
	if (!new_map)
		return (0);
	lines = process_map_line(new_map, &validation.player_coord,
			&validation.exit, &validation.collectibles);
	if (lines == 0 || lines != height || !validate_map_conditions(&validation,
			new_map) || flood_fill(new_map, &validation.player_coord,
			&validation.exit, &validation.collectibles) == 1
		|| validation.exit != 0 || validation.collectibles != 0)
		return (free_str_tab(new_map), 0);
	return (free_str_tab(new_map), 1);
}

int	check_border(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == 0 || y == height - 1)
			{
				if (map[y][x] != '1' && map[y][x] != '\0')
					return (0);
			}
			else if (x == 0 || x == width - 1)
			{
				if (map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
