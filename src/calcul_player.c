/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:23:54 by abosc             #+#    #+#             */
/*   Updated: 2025/01/16 23:56:59 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_player	*init_player(t_parameters *params)
{
	int			i;
	t_pos		coord;
	t_player	*player;

	i = -1;
	coord.x = 0;
	coord.y = 0;
	player = ft_calloc(1, sizeof(t_player));
	while (params->map[++i])
	{
		if (params->map[i] == 'P')
		{
			set_player_coord(player, &coord);
			return (coord, player);
		}
		coord.x++;
		if (params->map[i] == '\n')
		{
			coord.x = 0;
			coord.y++;
		}
	}
	return (player);
}

void	move_up(t_player *player, t_parameters *params)
{
	if (check_movement(params, (t_pos){player->pos_x, player->pos_y - 1}) == 1)
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
