/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:48:37 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/25 17:48:41 by ade-la-c         ###   ########.fr       */
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

char				*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = -1;
	if (!src)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char				*ft_strjoin(char *s1, char *s2, int b)
{
	int				i;
	int				j;
	char			*string;
	char			s1_new[ft_strlen(s1) + 1];
	char			s2_new[ft_strlen(s2) + 1];

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup(s2));
	ft_strcpy(s1_new, s1);
	free(s1);
	ft_strcpy(s2_new, s2);
	if (b == 1)
		free(s2);
	b = ft_strlen(s1_new) + ft_strlen(s2_new);
	if (!(string = (char *)malloc(sizeof(char) * (b + 1))))
		return (NULL);
	while (++i < ft_strlen(s1_new))
		string[i] = s1_new[i];
	while (++j < ft_strlen(s2_new))
		string[i + j] = s2_new[j];
	string[b] = '\0';
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
	{
		free(str);
		str = NULL;
		return (ft_strdup(""));
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		string[i] = s[start + i];
	free(str);
	str = NULL;
	string[i] = '\0';
	return (string);
}
