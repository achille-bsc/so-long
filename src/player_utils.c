/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 05:19:18 by abosc             #+#    #+#             */
/*   Updated: 2025/01/10 05:20:06 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	set_player_coord(t_player *player, t_pos *coord)
{
	player->pos_x = coord->x;
	player->pos_y = coord->y;
	player->orientation = "top";
}
