/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:29:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/02/15 20:46:05 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*line;
	int		nb_line;
	int		fd;
	int		fd2;
	int		fd3;

	if (ac < 3)
		return (0);
	nb_line = 1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	if ((fd2 = open(av[2], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	if ((fd3 = open(av[3], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	line = NULL;
	int ret = 0;
	while ((ret = get_next_line(fd, &line)) > 0 && nb_line)
	{
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		ret = get_next_line(fd2, &line);
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		ret = get_next_line(fd3, &line);
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		nb_line++;
	}
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	line = NULL;
	ret = get_next_line(fd2, &line);
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	line = NULL;
	ret = get_next_line(fd3, &line);
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	system("leaks a.out");
}
