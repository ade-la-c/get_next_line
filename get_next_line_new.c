/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:17:26 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/11 15:47:46 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_checker(char *str)
{
	size_t		i;

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

char			*ft_crop_line(char **str)
{
	char	*ret;
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!*str || ft_checker(*str) < 1)
		return (NULL);
	while (*str[len] && *str[len] != '\n')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len + 1] = '\0';
	while (i < len)
	{
		ret[i] = *str[i];
		i++;
	}
	if (!(tmp = ft_substr(*str, len + 1, ft_strlen(*str) - len - 1)))
		return (NULL);
	*str = tmp;
	return (ret);
}

char			*ft_crop_line2(char **str, char *buf)
{
	char		*ret;
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (!*str || ft_checker(*str) == 2)
		return (NULL);
	while (buf[len] && buf[len] != '\n')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len + 1] = '\0';
	while (i < len)
	{
		ret[i] = buf[i];
		i++;
	}
	if (!(*str = ft_substr(buf, len + 1, ft_strlen(buf) - len - 1)))
		return (NULL);
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	static char		*str[FD_SIZE];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];
	char			*tmp;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	str[fd] = NULL;
	tmp = NULL;
	if (fd < 0 || fd > OPEN_MAX || !*line || !BUFFER_SIZE)
		return (-1);
	while (ft_checker(str[fd]) > -1)
	{
		if (ft_checker(str[fd]) == 0)
		{
			tmp = ft_crop_line(&str[fd]);
			return (ret);
		}
		else if (ft_checker(str[fd]) == 1)
		{
			ft_crop_line(&str[fd]);
			tmp = str[fd];
			return (ret);
		}
		else
		{
			ft_strjoin(tmp, str[fd]);
			continue ;
		}
		while ((ret = read(fd, buf, BUFFER_SIZE)) > 1 && ft_checker(str[fd]) == -1)
		{
			if (ft_checker(buf) == 2)
			{
				tmp = ft_crop_line2(&str[fd], buf);
				return (ret);
			}
			else if (ft_checker(buf) == 1)
			{
				str[fd] = buf;
				str[fd] = ft_crop_line(&str[fd]);
				tmp = ft_strjoin(tmp, buf);
				return (ret);
			}
			else
				tmp = ft_strjoin(tmp, buf);
		}
	}
	tmp = *line;
	return (ret);
}
