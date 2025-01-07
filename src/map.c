/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 16:35:18 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_map(t_window *window, char *map, t_player)
{
	char	*map_chars;
	t_pos	*pos;
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	map_chars = read_file(fd);
	pos = malloc(sizeof(t_pos));
	if (!pos)
		return ;
	pos->x = 1;
	pos->y = 1;
	ft_printf("---\n");
	ft_printf("%s", map_chars);
	ft_printf("---\n");
	while (map_chars[i])
	{
		if (map_chars[i] == '0')
		{
			printer(*window, pos, "./assets/textures/floor.xpm");
			pos->x += 32;
		}
		else if (map_chars[i] == '1')
		{
			printer(*window, pos, "./assets/textures/wall.xpm");
			pos->x += 32;
		}
		else if (map_chars[i] == 'C')
		{
			printer(*window, pos, "./assets/textures/coin-bag.xpm");
			pos->x += 32;
		}
		else if (map_chars[i] == 'E')
		{
			printer(*window, pos, "./assets/textures/exit-opened.xpm");
			pos->x += 32;
		}
		else if (map_chars[i] == '\n')
		{
			pos->y += 32;
			pos->x = 0;
		}
		if (map_chars[i] == 'P')
		{
			// printer(*window, pos, "./assets/textures/floor.xpm");
			printer(*window, pos, "./assets/player/back.xpm");
			pos->x += 32;
		}
		i++;
	}
}
