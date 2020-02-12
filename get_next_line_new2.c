/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:36:06 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/12 04:53:25 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_checker(char *str)
{
	size_t			i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == 'i')
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
	char			*s1;
	int				i;
	int				len;

	i = 0;
	len = 0;
	s1 = (char *)*str;
	while (s2[len] && s2[len] != '\n')
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len + 1] = '\0';
	while (i < len)
	{
		ret[i] = s2[i];
		i++;
	}
	if (!(s1 = ft_substr(s2, len + 1, ft_strlen(s2) - len - 1)))
		return (NULL);
	*str = s1;
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static char		*str[OPEN_MAX];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	ret = 0;
	tmp = NULL;
	if (fd < 0 || fd > OPEN_MAX || !*line || BUFFER_SIZE < 1)
		return (-1);
	if (ft_checker(str[fd]) > 0)
	{
		tmp = ft_split_at_newline(&str[fd], *str);//printf("tmp1 = %s ~ static1 = %s\n", tmp, str[fd]);
		return (ret == 0 ? 0 : 1);
	}
	else if (ft_checker(str[fd]) == 0)
	{
		tmp = ft_strdup(str[fd]);
//	printf("tmp2 = %s ~ static2 = %s\n", tmp, str[fd]);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (ft_checker(buf) > 0)
		{
			tmp = ft_split_at_newline(&str[fd], buf);//printf("tmp3 = %s ~ static3 = %s\n", tmp, str[fd]);
			return (ret == 0 ? 0 : 1);
		}
		else
		{
			tmp = ft_split_at_newline(&str[fd], buf);
			tmp = ft_strjoin(tmp, buf);//printf("tmp4 = %s ~ static4 = %s\n", tmp, str[fd]);
		}
	}
	*line = tmp;
	return (ret == 0 ? 0 : 1);
}

int					main(void)
{
	int		fd = open("oui.txt", O_RDONLY);
	char	*line;
	int		ret;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d|%s\n", ret, line);
		free(line);
	}
	printf("%d|%s\n", ret, line);
	free(line);
	close(fd);
	return (0);
}
