/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 21:02:17 by abosc             #+#    #+#             */
/*   Updated: 2025/01/08 21:18:13 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_movement(t_parameters *params, t_pos coord)
{
	int		i;
	t_pos	actual_coord;

	i = 0;
	actual_coord = (t_pos){0, 0};
	while (params->map[i])
	{
		if (actual_coord.x == coord.x && actual_coord.y == coord.y && params->map[i] == '1')
			return (0);
		if (actual_coord.x == coord.x && actual_coord.y == coord.y && params->map[i] == 'E')
			return (0);
		i++;
	}
	return (1);
}
