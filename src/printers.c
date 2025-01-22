/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:17:43 by abosc             #+#    #+#             */
/*   Updated: 2025/01/22 00:15:08 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	printer(t_window win, t_pos *pos, char *pict)
{
	t_img	*img;
	int		width;
	int		height;

	width = 0;
	height = 0;
	img = mlx_xpm_file_to_image(win.mlx, pict, &width, &height);
	if (img)
		mlx_put_image_to_window(win.mlx, win.win, img, pos->x, pos->y);
	mlx_destroy_image(win.mlx, img);
}
