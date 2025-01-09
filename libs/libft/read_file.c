/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:01:08 by abosc             #+#    #+#             */
/*   Updated: 2025/01/08 15:50:44 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd)
{
	char	*line;
	char	*result;

	line = get_next_line(fd);
	result = "\0";
	while (line)
	{
		result = ft_strjoin(result, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (result);
}
// int main()
// {
// 	char *encule;
// 	encule = read_file(1);
// 	ft_printf("%s", encule);
// 	return (0);
// }
