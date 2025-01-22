/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:53:19 by achillebosc       #+#    #+#             */
/*   Updated: 2025/01/18 03:48:43 by abosc            ###   ########.fr       */
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
	t_pos	*up;
	t_pos	*down;
	t_pos	*left;
	t_pos	*right;

	if (map[coord->y][coord->x] == '1' || map[coord->y][coord->x] == 'V')
		return (1);
	if (map[coord->y][coord->x] == 'C')
		(*collectibles)--;
	else if (map[coord->y][coord->x] == 'E')
		(*exit)--;
	map[coord->y][coord->x] = 'V';
	up = ft_calloc(1, sizeof(t_pos));
	down = ft_calloc(1, sizeof(t_pos));
	left = ft_calloc(1, sizeof(t_pos));
	right = ft_calloc(1, sizeof(t_pos));
	if (!up || !down || !left || !right)
		return (1);
	up->x = coord->x;
	up->y = coord->y - 1;
	down->x = coord->x;
	down->y = coord->y + 1;
	left->x = coord->x - 1;
	left->y = coord->y;
	right->x = coord->x + 1;
	right->y = coord->y;
	flood_fill(map, up, exit, collectibles);
	flood_fill(map, down, exit, collectibles);
	flood_fill(map, left, exit, collectibles);
	flood_fill(map, right, exit, collectibles);
	free(up);
	free(down);
	free(left);
	free(right);
	return (0);
}

int	validate_map(char *map, int width, int height)
{
	int		exit;
	int		collectibles;
	t_pos	player_coord;
	int		x;
	int		y;
	char	**new_map;

	exit = 0;
	collectibles = 0;
	player_coord.x = -1;
	player_coord.y = -1;
	new_map = ft_split(map, '\n');
	if (!new_map)
		return (0);
	y = 0;
	while (new_map[y])
	{
		x = 0;
		while (new_map[y][x])
		{
			if (new_map[y][x] == 'C')
				collectibles++;
			else if (new_map[y][x] == 'E')
				exit++;
			else if (new_map[y][x] == 'P')
				player_coord = (t_pos){x, y};
			x++;
		}
		if (x != width)
			return (free_str_tab(new_map), 0);
		y++;
	}
	if (y != height)
		return (free_str_tab(new_map), 0);
	if (player_coord.x == -1 || player_coord.y == -1 || exit != 1
		|| collectibles == 0 || check_border(new_map, width, height) == 0 || flood_fill(new_map, &player_coord, &exit,
			&collectibles) == 1)
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
