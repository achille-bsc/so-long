/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:15:26 by abosc             #+#    #+#             */
/*   Updated: 2025/01/22 21:31:21 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	get_map_width(char *map)
{
	int	width;
	int	i;

	i = 0;
	width = 0;
	while (map[i] != '\n')
	{
		width++;
		i++;
	}
	return (width);
}

int	get_map_height(char *map)
{
	int	height;
	int	i;

	i = 0;
	height = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	return (height);
}

void	free_str_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
