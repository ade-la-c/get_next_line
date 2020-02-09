/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:07:43 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/09 13:42:17 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char		*ft_crop_line(char **str)
{
	char		*s1;
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (!*str)
		return (NULL);
	while (*str[len] && *str[len] != '\n')
		len++;
	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		s1[i] = *str[i];
		i++;
	}
	s1[i] = '\0';
	*str = ft_substr(*str, len + 1, ft_strlen(*str) - len + 1);
	return (s1);
}

static char		*ft_separate_line(char *buf, char **str)
{
	char		*s1;
	int			i;
	int			len;

	i = 0;
	len = 0;
	s1 = NULL;
	while (buf[len] && buf[len] != '\n')
		len++;
	if (!(s1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		s1[i] = buf[i];
		i++;
	}
	s1[i] = '\0';
	i++;
	if (!(*str = ft_strdup(&buf[i])))
		return (NULL);
	return (s1);
}

static int		ft_checker(char *str)
{
	size_t		i;
	
	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
		{
			if (i < ft_strlen(str))
				return (1);
			return (0);
		}
	return (-1);
}
/*
int				get_next_line(int fd, char **line)
{
	static char		*str[FD_SIZE];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];
	char			*tmp;
	int				i;
	int				ret;

	i = 0;
	str[fd] = NULL;
	tmp = NULL;
	if (fd < 0 || fd > OPEN_MAX || !line || !BUFFER_SIZE)
		return (-1);
	if (read(fd, buf, BUFFER_SIZE) == 0)
		return (0);
	if (ft_checker(str[fd]) != -1)
		ft_crop_line(&str[fd]);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_checker(buf) != -1)
			break ;
		else
			ft_strjoin(tmp, buf);
	}
	ft_separate_line(buf, &str[fd]);
	return (1);
}
*/
int				get_next_line(int fd, char **line)
{
	static char		*str[FD_SIZE];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];
	char			*tmp;
	int				i;
	int				ret;

	i = 0;
	str[fd] = NULL;
	tmp = NULL;
	if (fd < 0 || fd > OPEN_MAX || !line || !BUFFER_SIZE)
		return (-1);
	if (ft_checker(str[fd]) != -1)
		ft_crop_line(&str[fd]);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 && ft_checker(str[fd]) == -1)
		{
			ft_strjoin(tmp, str[fd]);
			if (ft_checker(buf) != -1)
			{
				ft_separate_line(buf, &str[fd]);
				break ;
			}
			else
				ft_strjoin(tmp, buf);
		}
	
	return (1);
}

int					main(void)
{
	int		fd = open("oui.txt", O_RDONLY);
	char	*line;
	int		ret;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d|%s\n", ret, line);
//		free(line);
	}
	printf("%d|%s\n", ret, line);
//	free(line);
	close(fd);
	return (0);
}
