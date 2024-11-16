/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achillebosc <achillebosc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:05:54 by achillebosc       #+#    #+#             */
/*   Updated: 2024/11/16 23:06:16 by achillebosc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_args(int argc, char **argv)
{
    if (argc != 2)
        return (ft_printf("Vous devez fournir 1 carte"));
    if (argc == 2)
    {
        if (!end_with(argv[1], ".ber"))
            ft_printf("La carte que vous avez fourni n'a pas le bon format");
        //vérif map lisible && existante && possible à finir && 
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (!check_args(argc, argv))
        return (ft_printf("Erreur\nCeci n'est pas le format attendu d'une carte. Voici le format attendu:\n<nonm_de_fichier>.ber\n*.ber"));
    return (0);
}