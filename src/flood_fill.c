/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achillebosc <achillebosc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:53:19 by achillebosc       #+#    #+#             */
/*   Updated: 2025/01/11 00:16:07 by achillebosc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_pos   search_start(t_parameters *params)
{
    t_pos   pos;
    int     i;

    i = 0;
    while (params->map[i])
    {
        if (params->map[i] == 'P')
            return (pos);
        i++;
        pos.x++;
        if (params->map[i] == '\n')
        {
            pos.y++;
            pos.x = 0;
        }
    }
    return (pos);
}

int flood_fill(char **map, t_pos *coord, int *exit, int *collectibles)
{
    // Si la case est hors de la map ou déjà visitée, on arrête
    if (map[coord->y][coord->x] == '1' || map[coord->y][coord->y] == 'V')
        return (1);

    // Si c'est une case importante (C ou E), on la marque comme atteignable
    if (map[coord->y][coord->x] == 'C')
        (*collectibles)--;
    else if (map[coord->y][coord->x] == 'E')
        (*exit)--;
    // On marque la case comme visitée
    map[coord->y][coord->x] = 'V';

    // Appel récursif pour explorer les cases adjacentes
    flood_fill(map, coord, &exit, &collectibles);
    flood_fill(map, coord, &exit, &collectibles);
    flood_fill(map, coord, &exit, &collectibles);
    flood_fill(map, coord, &exit, &collectibles);
    return (0);
}

int validate_map(char **map, int width, int height)
{
    int exit;
    int collectibles;
    t_pos   *player_coord;
    int x;
    int y;

    exit = 0;
    collectibles = 0;
    player_coord = (t_pos *){-1, -1};
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            if (map[y][x] == 'C')
                collectibles++;
            else if (map[y][x] == 'E')
                exit++;
            else if (map[y][x] == 'P')
            {
                player_coord->x = x;
                player_coord->y = y;
            }
            x++;
        }
        y++;
    }
    if (player_coord->x == -1 || player_coord->y == -1 || exit != 1 || collectibles == 0)
        return (0);
    if (flood_fill(map, player_coord, &exit, &collectibles) == 1)
        // TODO: exit(1);
}
