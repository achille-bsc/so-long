/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:23:54 by abosc             #+#    #+#             */
/*   Updated: 2025/01/08 21:32:25 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_player	*init_player(char *map)
{
	int			i;
	t_pos		*coord;
	t_player	*player;

	i = -1;
	coord = ft_calloc(1, sizeof(t_pos));
	coord->x = -1;
	coord->y = 0;
	player = ft_calloc(1, sizeof(t_player));
	while (map[++i])
	{
		if (map[i] == 'P')
		{
			player->pos_x = coord->x;
			player->pos_y = coord->y;
			player->orientation = "top";
			return (player);
		}
		coord->x++;
		if (map[i] == '\n')
		{
			coord->x = 0;
			coord->y++;
		}
	}
	return (player);
}

void	move_up(t_player *player, t_parameters *params)
{
	if (check_movement(params, (t_pos){player->pos_x, player->pos_y - 1}))
	{
		player->last_pos_x = player->pos_x;
		player->last_pos_y = player->pos_y;
		player->pos_y -= 1;
		player->orientation = "top";
	}
}

void	move_down(t_player *player, t_parameters *params)
{
	if (check_movement(params, (t_pos){player->pos_x, player->pos_y + 1}))
	{
		player->last_pos_x = player->pos_x;
		player->last_pos_y = player->pos_y;
		player->pos_y += 1;
		player->orientation = "bottom";
	}
}

void	move_left(t_player *player, t_parameters *params)
{
	if (check_movement(params, (t_pos){player->pos_x - 1, player->pos_y}))
	{
		player->last_pos_x = player->pos_x;
		player->last_pos_y = player->pos_y;
		player->pos_x -= 1;
		player->orientation = "left";
	}
}

void	move_right(t_player *player, t_parameters *params)
{
	if (check_movement(params, (t_pos){player->pos_x + 1, player->pos_y}))
	{
		player->last_pos_x = player->pos_x;
		player->last_pos_y = player->pos_y;
		player->pos_x += 1;
		player->orientation = "right";
	}
}
