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
 ** 
 ** 
*/

static int	ft_line_size(int fd, char **buff)
{
	int		size;
	char	*tmp;
	char	*bckp;

	tmp = ft_strnew(BUFF_SIZE + 1);
	while ((size = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		bckp = buff[fd];
		buff[fd] = ft_strjoin(buff[fd], tmp);
		free(bckp);
		if (!buff[fd])
			ft_strdup(tmp);
		ft_bzero(tmp, BUFF_SIZE);
	}
	free(tmp);
	if (size)
		return (1);
	return (0);
}

/*
 ** 
 **
 **
*/

static int	ft_read_line(int fd, char **buff, char **line)
{
	char	*tmp;
	char	*bckp;

	if ((tmp = ft_strchr(buff[fd], '\n'))
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
		buff[fd] = ft_strnew(BUFF_SIZE + 1);
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

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*buff[8192];
	
	if (fd < 0 || !line || BUFF_SIZE <= 0 || ft_line_size(fd, &buff[fd]))
		return (-1);

	if (ft_read_line(fd, &buff[fd], line))
		return (1);
	return (0);
}




// EXAMPLE

// Reads the size needed for the buffer
// Detect the length of each line
int		readlinewidth(int fd)
{
	char	buff[2];
	size_t	nbread;

	(void) memset((void*) buff, 0, (size_t) 2);
	nbread = read(fd, (void*) buff, (size_t) 2);
	if (nbread == -1 || nbread == 0)
		return (-1);
	return (atoi(buff));
}


// Reads of this size in a loop for each line
void	readandprintlines(int fd, size_t linewidth)
{
	char	*buff;
	size_t	nbread;

	buff = (char *)malloc((linewidth + 1) * sizeof(*buff));
	if (buff == NULL)
		return ;
	(void)memset((void*) buff, 0, linewidth + 1);
	while ((nbread = read(fd, (void*) buff, linewidth)) != 0)
	{
		printf("%s", buff);
		(void) memset((void*)buff, 0, linewidth);
	}
	free(buff);
	return ;
}

//Example of main file without GET_NEXT_LINE
int		example_main(void)
{
	int	fd;
	int	linewidth;
	
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	linewidth = readlinewidth(fd); //gets the line width from fd
	if (linewidth == -1 || linewidth == 0)
		return (-1);
	readandprintlines(fd, (size_t) linewidth); //reads in loop for each line
	close(fd);
	return (0);
}