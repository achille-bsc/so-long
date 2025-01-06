/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/06 10:58:01 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_map(t_window *window, char *map)
{
	char	*map_chars;
	t_pos	pos;
	int		fd;
	int		i;
	
	ft_printf("001\n");
	i = 0;
	fd = open(map, O_RDONLY);
	map_chars = read_file(fd) // GROS PB
	
	pos.x = 0;
	pos.y = 0;
	ft_printf("002\n");
	
	while (map_chars[i])
	{

		ft_printf("20%d\n", i);
		if (map_chars[i] == '0' || map_chars[i] == 'P')
			printer(*window, pos, "../textures/perso.xpm");
		else if (map_chars[i] == '0')
			printer(*window, pos, "../textures/perso.xpm");
		else if (map_chars[i] == 'C')
			printer(*window, pos, "../textures/perso.xpm");
		else if (map_chars[i] == 'E')
			printer(*window, pos, "../textures/perso.xpm");
		
		i++;
	}
}
