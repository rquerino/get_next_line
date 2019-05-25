/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 11:55:17 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/22 12:14:20 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* 
 ** pseudocode: 
 **
 ** 
 ** 
 **
*/


/*
 ** Stores the line on static array
 ** Returns 1 if there is more lines, 0 if end file.
*/ 
static int	ft_next_line(char **lines, char **line, int fd, int r)
{
	int j;

	size = 0;
	while (line[fd][j] != '\n')
	{
		while ()
		lines[fd][j] = line[fd][j];
		j++;
	}
	return (1);
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

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*storage[8192];
	
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!storage[fd])
		storage[fd] = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(0);
	if (*storage[fd])
		if (ft_next_line(storage[fd], line))
			return (1);
	while (ret = read(fd, storage[fd], BUFF_SIZE))
	{
		if (ret < 0)
			return (-1);
		if (ft_next_line(storage[fd], line))
			return (1);
	}
	if (**line = 0)
		return (1);
	return (1);
}