/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achillebosc <achillebosc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:50 by abosc             #+#    #+#             */
/*   Updated: 2025/01/12 15:14:06 by achillebosc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "structures.h"

# define EVENT_CLOSE 17
# define MASK_NO_EVENT 0
# define FPS 120
void			draw_map(char *map_chars, t_player *player,
					t_parameters *params);
void			printer(t_window win, t_pos *pos, char *pict);
void			mapper(char *map_chars, t_pos *pos, t_player *player,
					t_parameters *params);
t_player		*init_player(t_parameters *params);
void			move_up(t_player *player, t_parameters *params);
void			move_down(t_player *player, t_parameters *params);
void			move_left(t_player *player, t_parameters *params);
void			move_right(t_player *player, t_parameters *params);
int				check_movement(t_parameters *params, t_pos coord);
int				load_collectibles(char *map);
void			draw_texture(t_window *window, t_pos *pos, char map_char,
					char *orientation);

// Utils
char			*get_map(int argc, char **argv);
void			*create_window(void *mlx);
void			*create_mlx(void);
t_parameters	*init_parameters(void);
char			*load_map(char *map);

// map_utils
void			update_coord(t_pos *pos2, t_player *player);
void			player_checker(t_parameters *params, int x, int y, int i);
void			increment_coords(int *x, int *y, t_pos *pos);
void			exec_player(t_parameters *params);
// Player utils
void			set_player_coord(t_player *player, t_pos *coord);


int validate_map(char **map, int width, int height);
#endif
