/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:34:50 by abosc             #+#    #+#             */
/*   Updated: 2025/01/24 01:05:48 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
void			draw_texture(t_pos *pos, t_parameters *params, char map_char,
					char *orientation);
int				close_window(t_parameters *param, int err);

// Utils
char			*get_map(int argc, char **argv, void *mlx,
					t_parameters *params);
void			*create_window(void *mlx, t_parameters *params);
void			*create_mlx(void);
t_parameters	*init_parameters(void);
char			*load_map(char *map, void *mlx, t_parameters *params);

// Utils 2
int				get_map_width(char *map);
int				get_map_height(char *map);
void			free_str_tab(char **tab);
// map_utils
void			update_coord(t_pos *pos2, t_player *player);
void			player_checker(t_parameters *params, int x, int y, int i);
void			increment_coords(int *x, int *y, t_pos *pos);
void			exec_player(t_parameters *params);
// Player utils
void			set_player_coord(t_player *player, t_pos *coord);

// Flood fill
int				validate_map(char *map, int width, int height);
int				check_border(char **map, int width, int height);
int				flood_fill(char **map, t_pos *coord, int *exit,
					int *collectibles);

// ff utils
int				process_map_line(char **new_map, t_pos *player_coord, int *exit,
					int *collectibles);
t_pos			*allocate_position(int x, int y);
int				check_position(char **map, t_pos *coord, int *exit,
					int *collectibles);
int				process_neighbors(char **map, t_pos *coord, int *exit,
					int *collectibles);
int				validate_map_conditions(t_map_validation *validation,
					char **new_map);

#endif
