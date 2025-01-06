/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:17:43 by abosc             #+#    #+#             */
/*   Updated: 2025/01/06 10:26:41 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	printer(t_window win, t_pos pos, char	*pict)
{
	mlx_xpm_file_to_image(win.mlx, pict, &pos.x, &pos.y);
	pos.x += 16;
	pos.y += 16;
}
