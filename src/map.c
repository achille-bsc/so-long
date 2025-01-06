/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/06 15:16:15 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_map(t_window *window, char *map)
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
		if (map_chars[i] == '0' || map_chars[i] == 'P')
			printer(*window, pos, "./textures/perso.xpm");
		else if (map_chars[i] == '1')
			printer(*window, pos, "./textures/perso.xpm");
		else if (map_chars[i] == 'C')
			printer(*window, pos, "./textures/perso.xpm");
		else if (map_chars[i] == 'E')
			printer(*window, pos, "./textures/perso.xpm");
		i++;
	}
}
