/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:49:35 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/25 19:28:45 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# include "leak-detector/leak_detector.h"

int				get_next_line(int fd, char **line);

int				ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
int				ft_free(char *str, int i);
char			*ft_strjoin(char *s1, char *s2, int b);
char			*ft_strdup(const char *s1);
char			*ft_substr(char *s, int start, int len, char *str);

#endif
