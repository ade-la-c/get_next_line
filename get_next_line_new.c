/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:17:26 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/09 19:28:01 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static int		ft_checker(char *str)
{
	size_t		i;
	
	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i] == '\n')
		{
			if (i < ft_strlen(str))
				return (2);
			return (1);
		}
	return (0);
}
*/
char		*ft_crop_line(char **str)
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
	if (!(*str = ft_substr(*str, len, ft_strlen(*str) - len)))
		return (NULL);
	return (s1);
}

int				main(void)
{
	char		*line = "12345\n9";
	char		*str;
	str = ft_crop_line(&line);
	printf("%s\n%s\n", str, line);
}
/*
int			get_next_line(int fd, char  **line)
{
	
	static char		*str[FD_SIZE];
	char			buf[BUFFER_SIZE < 0 ? 0 : BUFFER_SIZE + 1];
	char			*tmp;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	str[fd] = NULL;
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
			return (ret);
		}
		else
	}
	tmp = *line;
	return (ret);
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
*/