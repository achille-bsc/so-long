/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:57:47 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 22:28:24 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	process_map_line(char **new_map, t_pos *player_coord, int *exit,
		int *collectibles)
{
	t_pos	coord;

	coord.y = 0;
	while (new_map[coord.y])
	{
		coord.x = 0;
		while (new_map[coord.y][coord.x])
		{
			if (new_map[coord.y][coord.x] == 'C')
				(*collectibles)++;
			else if (new_map[coord.y][coord.x] == 'E')
				(*exit)++;
			else if (new_map[coord.y][coord.x] == 'P')
				*player_coord = (t_pos){coord.x, coord.y};
			coord.x++;
		}
		if (coord.x != (int)ft_strlen(new_map[0]))
			return (0);
		coord.y++;
	}
	return (coord.y);
}

int	validate_map_conditions(t_map_validation *validation, char **new_map)
{
	if (validation->player_coord.x == -1 || validation->player_coord.y == -1
		|| validation->exit != 1 || validation->collectibles == 0
		|| check_border(new_map, validation->width, validation->height) == 0)
		return (0);
	return (1);
}

t_pos	*allocate_position(int x, int y)
{
	t_pos	*pos;

	pos = ft_calloc(1, sizeof(t_pos));
	if (!pos)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

int	check_position(char **map, t_pos *coord, int *exit, int *collectibles)
{
	if (coord->y < 0 || coord->x < 0 || !map[coord->y] || !map[coord->y][coord->x])
        return (1);
	if (map[coord->y][coord->x] == 'C')
		(*collectibles)--;
	if (map[coord->y][coord->x] == 'E')
		(*exit)--;
	if (map[coord->y][coord->x] == '1' || map[coord->y][coord->x] == 'V'
		|| map[coord->y][coord->x] == 'E')
		return (1);
	map[coord->y][coord->x] = 'V';
	return (0);
}

int	process_neighbors(char **map, t_pos *coord, int *exit, int *collectibles)
{
	t_pos	*up;
	t_pos	*down;
	t_pos	*left;
	t_pos	*right;

	up = allocate_position(coord->x, coord->y - 1);
	down = allocate_position(coord->x, coord->y + 1);
	left = allocate_position(coord->x - 1, coord->y);
	right = allocate_position(coord->x + 1, coord->y);
	if (!up || !down || !left || !right)
		return (1);
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
