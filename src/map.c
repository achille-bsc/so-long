/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/08 16:07:56 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_texture(t_window *window, t_pos *pos, char map_char,
		char *orientation)
{
	if (map_char == '0' || map_char == 'P')
		printer(*window, pos, "./assets/textures/floor.xpm");
	else if (map_char == '1')
		printer(*window, pos, "./assets/textures/wall.xpm");
	else if (map_char == 'C')
		printer(*window, pos, "./assets/textures/coin-bag.xpm");
	else if (map_char == 'E')
		printer(*window, pos, "./assets/textures/exit-opened.xpm");
	else if (map_char == 'E')
		printer(*window, pos, "./assets/textures/exit-opened.xpm");
	else if (map_char == 'p')
	{
		if (!ft_strncmp(orientation, "top", 3))
			printer(*window, pos, "./assets/player/back.xpm");
		else if (!ft_strncmp(orientation, "bottom", 6))
			printer(*window, pos, "./assets/player/front.xpm");
		else if (!ft_strncmp(orientation, "left", 4))
			printer(*window, pos, "./assets/player/left.xpm");
		else if (!ft_strncmp(orientation, "right", 5))
			printer(*window, pos, "./assets/player/right.xpm");
	}
}

void	mapper(char *map_chars, t_window *window, t_pos *pos, t_player *player)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (map_chars[i])
	{
		if (player->pos_x == x && player->pos_y == y && map_chars[i] == '1')
		{
			t_pos	*pos2;
			
			pos2 = ft_calloc(1, sizeof(t_pos));
			if (!pos2)
				return ;
			pos2->x = player->last_pos_x;
			pos2->y = player->last_pos_y;
			player->pos_x = player->last_pos_x;
			player->pos_y = player->last_pos_y;
			draw_texture(window, pos2, 'p', player->orientation);
			
		}
		else if (player->pos_x == x && player->pos_y == y)
			draw_texture(window, pos, 'p', player->orientation);
		else
			draw_texture(window, pos, map_chars[i], player->orientation);
		pos->x += 32;
		x += 1;
		if (map_chars[i] == '\n')
		{
			pos->y += 32;
			pos->x = 0;
			y += 1;
			x = 0;
		}
		i++;
	}
}

void	draw_map(t_window *window, char *map_chars, t_player *player)
{
	t_pos	*pos;

	pos = ft_calloc(1, sizeof(t_pos));
	if (!pos)
		return ;
	pos->x = 1;
	pos->y = 1;
	mapper(map_chars, window, pos, player);
	free(pos);
}
