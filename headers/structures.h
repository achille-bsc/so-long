/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:33 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 16:34:36 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_personage
{
	int		pos_x;
	int		pos_y;
	void	*texture;
}			t_personage;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}			t_window;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_player
{
	int		pos_x;
	int		pos_Y;
	char	*orientation;
}			t_player;
