/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:36:48 by abosc             #+#    #+#             */
/*   Updated: 2025/01/06 12:01:23 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1  
# endif

# include <stdlib.h>
# include <unistd.h> 
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_endl(char *str);
char	*ft_get_line(char *buffer);
char	*ft_new_str(char *buffer);
char	*ft_read_str(int fd, char *buffer);
char	*get_next_line(int fd);

#endif
