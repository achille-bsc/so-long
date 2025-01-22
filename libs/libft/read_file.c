/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:01:08 by abosc             #+#    #+#             */
/*   Updated: 2025/01/21 20:39:42 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd)
{
	char	*line;
	char	*result;
	char	*tmp;

	result = ft_calloc(1, sizeof(char));
	if (!result)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = result;
		result = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (!result) // Vérification après ft_strjoin
			return (NULL);
	}
	return (result);
}

// int main()
// {
// 	char *encule;
// 	encule = read_file(1);
// 	ft_printf("%s", encule);
// 	return (0);
// }
