/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainigo-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:35:32 by ainigo-l          #+#    #+#             */
/*   Updated: 2024/11/25 16:35:35 by ainigo-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_freeall(char **s);
char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *dst, char *src);
char	*ft_substr(char *s, int start, int size);
char	*ft_strchr(char *s, int c);

#endif
