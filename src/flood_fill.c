/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:53:19 by achillebosc       #+#    #+#             */
/*   Updated: 2025/01/29 00:31:35 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_pos	search_start(t_parameters *params)
{
	t_pos	pos;
	int		i;

	i = 0;
	pos = (t_pos){0, 0};
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
	t_pos	up;
	t_pos	down;
	t_pos	left;
	t_pos	right;
	int		condition;

	condition = ff_confitionals(map, coord, collectibles, exit);
	if (condition == 1)
		return (1);
	if (condition == 0)
		return (0);
	map[coord->y][coord->x] = 'V';
	up = (t_pos){coord->x, coord->y - 1};
	down = (t_pos){coord->x, coord->y + 1};
	left = (t_pos){coord->x - 1, coord->y};
	right = (t_pos){coord->x + 1, coord->y};
	flood_fill(map, &up, exit, collectibles);
	flood_fill(map, &down, exit, collectibles);
	flood_fill(map, &left, exit, collectibles);
	flood_fill(map, &right, exit, collectibles);
	return (0);
}

int	validate_map(char *map, int width, int height)
{
	t_map_validation	validation;
	char				**new_map;
	int					lines;

	if (ft_strlen(map) == 0)
		return (0);
	validation = (t_map_validation){(t_pos){-1, -1}, 0, 0, width, height};
	new_map = ft_split(map, '\n');
	if (!new_map)
		return (0);
	lines = process_map_line(new_map, &validation.player_coord,
			&validation.exit, &validation.collectibles);
	if (lines == 0 || lines != height || validate_map_conditions(&validation,
			new_map) == 0 || flood_fill(new_map, &validation.player_coord,
			&validation.exit, &validation.collectibles) == 1
		|| validation.exit != 0 || validation.collectibles != 0)
		return (free_str_tab(new_map), 0);
	return (free_str_tab(new_map), 1);
}

int	validate_border_element(char **map, t_pos pos, t_pos size, int *starter)
{
	if (!ft_strchr("EPC01", map[pos.y][pos.x]))
		return (0);
	if (map[pos.y][pos.x] == 'P')
		(*starter)++;
	if (*starter > 1)
		return (0);
	if (pos.y == 0 || pos.y == size.y - 1)
	{
		if (map[pos.y][pos.x] != '1' && map[pos.y][pos.x] != '\0')
			return (0);
	}
	else if (pos.x == 0 || pos.x == size.x - 1)
	{
		if (map[pos.y][pos.x] != '1')
			return (0);
	}
	return (1);
}

int	check_border(char **map, int width, int height)
{
	t_pos	pos;
	t_pos	size;
	int		starter;

	pos.y = 0;
	starter = 0;
	size.x = width;
	size.y = height;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (!validate_border_element(map, pos, size, &starter))
				return (0);
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}
