/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:29:01 by rquerino          #+#    #+#             */
/*   Updated: 2019/06/10 12:25:54 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/* main for testing 1 fd */
int		main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret;
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			i = 0;
			fd = open(argv[1], O_RDONLY);
			while((ret = get_next_line(fd, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
			}
			close(fd);
       	}
	}
	return (1);
}

/* main for testing multiple fds */
/*
int		main(int argc, char **argv)
{
	int fd;
 	int fd2;
	char *line;
	int ret;
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			i = 0;
			fd = open(argv[1], O_RDONLY);
			while((ret = get_next_line(fd, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
			}
			close(fd);
			i = 0;
			fd2 = open(argv[2], O_RDONLY);
			while((ret = get_next_line(fd2, &line)) == 1)
			{
				i++;
				printf("MAIN:%d, line>%s\n", ret, line);
			}
			close(fd2);
		}
	}
	return (1);
}
*/
/* main for testing multiple fds calling gnl on first 3 lines from every file */
/*
int		main(int argc, char **argv)
{
	int fd;
 	int fd2;
	char *line;
	int ret;
	int i;

	if (argc >= 2)
	{
		if (access(argv[1], F_OK) == 0)
		{
			fd = open(argv[1], O_RDONLY);
			fd2 = open(argv[2], O_RDONLY);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("MAIN:%d, line1>%s\n", ret, line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("MAIN:%d, line1>%s\n", ret, line);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("MAIN:%d, line2>%s\n", ret, line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("MAIN:%d, line2>%s\n", ret, line);
			ret = get_next_line(fd, &line);
			if (ret == 1)
				printf("MAIN:%d, line3>%s\n", ret, line);
			ret = get_next_line(fd2, &line);
			if (ret == 1)
				printf("MAIN:%d, line3>%s\n", ret, line);
			close(fd);
			close(fd2);
		}
	}
	return (1);
}
*/
