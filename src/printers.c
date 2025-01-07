/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:17:43 by abosc             #+#    #+#             */
/*   Updated: 2025/01/07 16:14:58 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	printer(t_window win, t_pos *pos, char *pict)
{
	t_img	*img;
	int		width = 0;
	int		height = 0;

	img = mlx_xpm_file_to_image(win.mlx, pict, &width, &height);
	mlx_put_image_to_window(win.mlx, win.win, img, pos->x, pos->y);
}
