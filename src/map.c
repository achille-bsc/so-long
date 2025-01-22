/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:37:31 by abosc             #+#    #+#             */
/*   Updated: 2025/01/22 00:28:05 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	draw_texture(t_pos *pos, t_parameters *params, char map_char,
		char *orientation)
{
	if (map_char == '0' || map_char == 'P')
		printer(*params->window, pos, "./assets/textures/floor.xpm");
	else if (map_char == '1')
		printer(*params->window, pos, "./assets/textures/wall.xpm");
	else if (map_char == 'C')
		printer(*params->window, pos, "./assets/textures/coin-bag.xpm");
	else if (map_char == 'E' && params->player->can_exit)
		printer(*params->window, pos, "./assets/textures/exit-opened.xpm");
	else if (map_char == 'E')
		printer(*params->window, pos, "./assets/textures/exit-closed.xpm");
	else if (map_char == 'p')
	{
		if (!ft_strncmp(orientation, "top", 3))
			printer(*params->window, pos, "./assets/player/back.xpm");
		else if (!ft_strncmp(orientation, "bottom", 6))
			printer(*params->window, pos, "./assets/player/front.xpm");
		else if (!ft_strncmp(orientation, "left", 4))
			printer(*params->window, pos, "./assets/player/left.xpm");
		else if (!ft_strncmp(orientation, "right", 5))
			printer(*params->window, pos, "./assets/player/right.xpm");
	}
}

void	mapper(char *map_chars, t_pos *pos, t_player *player,
		t_parameters *params)
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
			exec_player(params);
		else if (player->pos_x == x && player->pos_y == y)
			draw_texture(pos, params, 'p', player->orientation);
		else
			draw_texture(pos, params, map_chars[i], player->orientation);
		player_checker(params, x, y, i);
		pos->x += 32;
		x += 1;
		if (map_chars[i] == '\n')
			increment_coords(&x, &y, pos);
		i++;
	}
}

void	draw_map(char *map_chars, t_player *player, t_parameters *params)
{
	t_pos	pos;

	pos.x = 1;
	pos.y = 1;
	mapper(map_chars, &pos, player, params);
}
 
