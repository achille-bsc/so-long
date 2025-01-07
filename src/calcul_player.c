/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:23:54 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 20:18:24 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_player	*init_player(char *map)
{
	int			i;
	int			x;
	int			y;
	t_player	*player;

	i = 0;
	x = 0;
	y = 0;
	player = malloc(sizeof(t_player));
	while (map[i])
	{
		if (map[i] == 'P')
		{
			player->pos_x = x;
			player->pos_y = y;
			player->orientation = "top";
			player->moved = 0;
			return (player);
		}
		x++;
		if (map[i] == '\n')
		{
			y++;
			x = 0;
		}
		i++;
	}
	return (player);
}

void	move_up(t_player *player)
{
	player->pos_y -= 1;
	player->orientation = "top";
}

void	move_down(t_player *player)
{
	player->pos_y += 1;
	player->orientation = "bottom";
}

void	move_left(t_player *player)
{
	player->pos_x -= 1;
	player->orientation = "left";
}

void	move_right(t_player *player)
{
	player->pos_x += 1;
	player->orientation = "right";
}
