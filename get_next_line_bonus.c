/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:49:02 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/25 17:49:07 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_checker(char *str)
{
	int				i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == '\n')
		{
			if (i < ft_strlen(str) - 1)
				return (2);
			return (1);
		}
	return (0);
}

static char			*ft_split_at_newline(char **str, char *s2)
{
	char			*ret;
	int				i;
	int				len;

	i = -1;
	len = 0;
	while (s2[len] && s2[len] != '\n')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (++i < len)
		ret[i] = s2[i];
	if (!(*str = ft_substr(s2, len + 1, ft_strlen(s2) - len - 1, *str)))
		return (NULL);
	return (ret);
}

int					gnl_be_longboi(int fd, char **line, char **str, char *buf)
{
	int				ret;

	ret = 0;
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_checker(buf) > 0)
		{
			*line = ft_strjoin(*line, ft_split_at_newline(str, buf), 1);
			break ;
		}
		else
			*line = ft_strjoin(*line, buf, 0);
	}
	return (ret == 0 ? 0 : 1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];

	*line = ft_strdup("");
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1
	|| read(fd, buf, 0) < 0)
		return (-1);
	buf[BUFFER_SIZE] = '\0';
	if (ft_checker(str[fd]) > 0)
	{
		free(*line);
		*line = ft_split_at_newline(&str[fd], str[fd]);
		return (1);
	}
	else if (ft_checker(str[fd]) == 0)
	{
		free(*line);
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
	}
	return (gnl_be_longboi(fd, line, &str[fd], buf));
}
