/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:38:26 by abosc             #+#    #+#             */
/*   Updated: 2025/01/10 01:51:27 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	load_collectibles(char *map)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			counter += 1;
		i++;
	}
	return (counter);
}
