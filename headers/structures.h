/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:33 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 20:13:20 by abosc            ###   ########.fr       */
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
	char		*orientation;
	int			moved;
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
}				t_parameters;
