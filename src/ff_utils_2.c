/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:19:55 by abosc             #+#    #+#             */
/*   Updated: 2025/01/29 00:31:44 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ff_confitionals(char **map, t_pos *coord, int *collectibles, int *exit)
{
	if (map[coord->y][coord->x] == '1' || map[coord->y][coord->x] == 'V')
		return (1);
	if (map[coord->y][coord->x] == 'C')
		(*collectibles)--;
	if (map[coord->y][coord->x] == 'E')
	{
		if (*exit > 0)
			(*exit)--;
		map[coord->y][coord->x] = 'V';
		return (0);
	}
	return (-1);
}
