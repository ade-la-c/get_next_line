/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:18:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/19 22:48:29 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char				*ft_strjoin(char *s1, char *s2, int c)
{
	long int		i;
	long int		j;
	char			*string;
	char			*s1_new;
	char			*s2_new;

	i = -1;
	j = -1;
	c = 0;
	if (!s1)
		return (ft_strdup(s2));
	s1_new = s1;
	free(s1);
	s2_new = s2;
	if (c == 1)
		free(s2);
	c = ft_strlen(s1) + ft_strlen(s2);
	if (!(string = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	while (++i < (long int)ft_strlen(s1_new))
		string[i] = s1_new[i];
	while (++j < (long int)ft_strlen(s2_new))
		string[i + j] = s2_new[j];
	string[c] = '\0';
	return (string);
}

char				*ft_strdup(const char *s1)
{
	int				i;
	char			*string;
	int				size;

	i = 0;
	size = ft_strlen(s1);
	string = NULL;
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char				*ft_substr(char *s, int start, int len, char *str)
{
	char			*string;
	int				i;

	i = -1;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		string[i] = s[start + i];
	free(str);
	string[i] = '\0';
	return (string);
}
