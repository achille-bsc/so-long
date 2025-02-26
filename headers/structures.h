/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:33 by abosc             #+#    #+#             */
/*   Updated: 2025/01/24 01:02:52 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_personage
{
	int			pos_x;
	int			pos_y;
	void		*texture;
}				t_personage;

typedef struct s_window
{
	void		*mlx;
	void		*win;
}				t_window;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
	int			last_pos_x;
	int			last_pos_y;
	char		*orientation;
	int			moved;
	int			collected;
	int			steps;
	int			can_exit;
}				t_player;

typedef struct s_checker_infos
{
	char		*map_chars;
	int			i;
	int			x;
	int			y;
}				t_checker_infos;

typedef struct s_parameters
{
	t_window	*window;
	char		*map;
	t_player	*player;
	int			collectibles_count;
	int			img_count;
}				t_parameters;

typedef struct s_map_validation
{
	t_pos		player_coord;
	int			exit;
	int			collectibles;
	int			width;
	int			height;
}				t_map_validation;
