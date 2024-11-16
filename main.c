/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achillebosc <achillebosc@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:05:54 by achillebosc       #+#    #+#             */
/*   Updated: 2024/11/16 20:08:49 by achillebosc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
    if (!check_args())
        return (printf("Erreur\nCeci n'est pas le format attendu d'une carte. Voici le format attendu:\n<nonm_de_fichier>.ber\n*.ber"));
    return (0);
}