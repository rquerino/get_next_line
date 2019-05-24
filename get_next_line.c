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

#include "libft.h"
#include <unistd.h>

/* 
 ** pseudocode: 
 **
 ** 
 ** 
 **
*/




static int	ft_read()
{


}

/*
 ** Stores the line on static array
 ** Returns 1 if there is more lines, 0 if end file.
*/ 
static int	ft_next_line(int fd, int i, char *dst, char **src)
{
	int j;

	j = 0;
	while (line[j] != '\n')
	{
		dst[i][j] = src[j];
		j++;
	}
	return (1);
}

/*
 ** Reads a file line by line.
 ** First parameter is the file descriptor used to read, second parameter 
 ** is the adress of pointer to a character that will be used to save
 ** the line read from the file descriptor. 
 ** Returns -1 error, 0 rear completed, 1 line read. 
 ** Functions allowed: libft, read(), malloc() and free().
 ** Bonus: use one single static variable, use multiple fd.
*/

int		get_next_line(const int fd, char **line)
{
	int			r;
	int			i;
	static char	*lines[8192];
	
	i = 0;
	j = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	while (r = read(fd, line, BUFF_SIZE)
	{
		while (line[j] != '\n')
		{
			ft_next_line(fd, i, lines, line);
		}
		i++;
	}


}

/*
 ** Easiest way using fgets, fputs and fclose
*/
int		main()
{
	static const char filename[] = "file.txt";
	FILE *file = fopen ( filename, "r" );
	if ( file != NULL )
	{
		char line [ 128 ]; /* or other suitable maximum line size */
		while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
		{
			fputs ( line, stdout ); /* write the line */
		}
		fclose ( file );
	}
	else
	{
		perror ( filename ); /* why didn't the file open? */
	}
	return (0);
}