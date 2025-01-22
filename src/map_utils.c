/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 04:36:58 by abosc             #+#    #+#             */
/*   Updated: 2025/01/22 00:22:53 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	update_coord(t_pos *pos2, t_player *player)
{
	pos2 = ft_calloc(1, sizeof(t_pos));
	if (!pos2)
		return ;
	pos2->x = player->last_pos_x * 32;
	pos2->y = player->last_pos_y * 32;
	player->pos_x = player->last_pos_x;
	player->pos_y = player->last_pos_y;
}

void	player_checker(t_parameters *params, int x, int y, int i)
{
	if (params->map[i] == 'C' && params->player->pos_x == x
		&& params->player->pos_y == y)
	{
		params->map[i] = '0';
		params->player->collected += 1;
	}
	if (params->player->collected == params->collectibles_count
		&& !(params->player->can_exit))
		params->player->can_exit = 1;
	if (params->map[i] == 'E' && params->player->pos_x == x
		&& params->player->pos_y == y && params->player->can_exit)
		close_window(params);
}

void	increment_coords(int *x, int *y, t_pos *pos)
{
	pos->x = 0;
	pos->y += 32;
	*y += 1;
	*x = 0;
}

void	exec_player(t_parameters *params)
{
	t_pos	*pos2;

	pos2 = NULL;
	update_coord(pos2, params->player);
	draw_texture(pos2, params, 'p', params->player->orientation);
	free(pos2);
}
