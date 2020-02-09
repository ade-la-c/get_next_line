/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:08:45 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/09 19:23:41 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define FD_SIZE 4096

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);

size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s1);
char		*ft_substr(char *s, unsigned int start, unsigned int len);

#endif
