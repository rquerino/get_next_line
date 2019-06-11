/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:55:17 by rquerino          #+#    #+#             */
/*   Updated: 2019/06/08 13:16:39 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Checks if buff can reach end of file on fd's full size using
** BUFF_SIZE on read(). Returns 1 if can't, 0 if ok.
*/

static int	ft_check_line(int fd, char **buff)
{
	int		r;
	char	*tmp;
	char	*bckp;

	tmp = ft_strnew(BUFF_SIZE + 1);
	while ((r = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		bckp = buff[fd];
		buff[fd] = ft_strjoin(buff[fd], tmp);
		free(bckp);
		if (!buff[fd])
			buff[fd] = ft_strdup(tmp);
		ft_bzero(tmp, BUFF_SIZE);
	}
	free(tmp);
	if (r)
		return (1);
	return (0);
}

/*
** Buff the fd's using BUFF_SIZE until '\n' is found, then returns 1.
** If it's the end of file, returns 0.
*/

static int	ft_read_line(int fd, char **buff, char **line)
{
	char	*tmp;
	char	*bckp;

	if ((tmp = ft_strchr(buff[fd], '\n')))
	{
		bckp = buff[fd];
		*tmp = '\0';
		*line = ft_strdup(buff[fd]);
		buff[fd] = ft_strdup(tmp + 1);
		free(bckp);
		return (1);
	}
	if (*buff[fd])
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (0);
}

/*
** Reads a file line by line.
** First parameter is the file descriptor used to read, second parameter
** is the adress of pointer to a character that will be used to save
** the line read from the file descriptor.
** Returns -1 error, 0 read completed, 1 line read.
** Functions allowed: libft, read(), malloc() and free().
** Bonus: use one single static variable, use multiple fd.
*/

int			get_next_line(const int fd, char **line)
{
	static char	*buff[4864];

	if (fd < 0 || !line || BUFF_SIZE <= 0 || ft_check_line(fd, &buff[fd]))
		return (-1);
	if (ft_read_line(fd, &buff[fd], line))
		return (1);
	return (0);
}
