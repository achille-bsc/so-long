/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:50 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 20:14:22 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "structures.h"

void		draw_map(t_window *window, char *map, t_player *player);
void		printer(t_window win, t_pos *pos, char *pict);
void		mapper(char *map_chars, t_window *window, t_pos *pos,
				t_player *player);
t_player	*init_player(char *map);
void		move_up(t_player *player);
void		move_down(t_player *player);
void		move_left(t_player *player);
void		move_right(t_player *player);

#endif
