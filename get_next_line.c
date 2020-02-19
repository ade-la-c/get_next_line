/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:36:06 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/20 00:16:30 by ade-la-c         ###   ########.fr       */
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

	i = 0;
	len = 0;
	while (s2[len] && s2[len] != '\n')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (i < len)
	{
		ret[i] = s2[i];
		i++;
	}//printf("~~%s\n", ret);
	if (!(*str = ft_substr(s2, len + 1, ft_strlen(s2) - len - 1, *str)))
		return (NULL);
	return (ret);
}

static int			ft_free(char *str, int i)
{
	free(str);
	str = NULL;
	return (i);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];
	int				ret;

	ret = 0;
	*line = ft_strdup("");
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
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
		str[fd] = NULL;
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_checker(buf) > 0)
		{
//			free(*line);
			*line = ft_strjoin(*line, ft_split_at_newline(&str[fd], buf), 1);
			break ;
		}
		else
			*line = ft_strjoin(*line, buf, 0);
	}
	return (ret == 0 ? ft_free(str[fd], 0) : 1);
}
/*
int					main(void)
{
	int		fd = open("oui.txt", O_RDONLY);
	char	*line;
	int		ret;
	int		i = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		i++;
		printf("%d %d|%s\n", i, ret, line);
		free(line);
	}
	printf("%d %d|%s\n", ++i, ret, line);
	free(line);
	close(fd);
//	system("leaks a.out");
	CHECK
	return (0);
}
*/