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

/*
** Verify if whatever is in the stack, has a newline. If it doesn't, returns
** a zero (0) to indicate that it's not valid. If there is a newline, we make a
** copy of the stack into the line, and we copied whatever was in the stack
** before, back to the stack (with the temporary stack that we created).
*/

static int			ft_check_lines(char **stack, char **line)
{
	char			*tmp;
	char			*copy;
	int				i;

	i = 0;
	copy = *stack;
	while (copy[i] != '\n')
		if (!copy[i++])
			return (0);
	tmp = &copy[i];
	*tmp = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(copy + 1);
	return (1);
}

/*
** Reads into the heap, from the file descriptors, a specific number of bytes
** defined by the BUFF_SIZE macro in the get_nex_line.h file. It's going to
** continue the reading when the return value of the read function is greater
** than zero (no errors, or if there is nothing else to read).
** If there is something in the stack, we will concatinate whatever is in
** there, with whatever is read in the heap. If no, we will just add
** whatever is in the heap into the stack. Then we will verify the stack to
** see if there is a newline. If there is, we will break from the while loop
** and force the positive ret value into a one (1), using the RET_VALUE() macro.
** This answer form SO helped me visualize the stack and heap in a better way:
** http://stackoverflow.com/a/1213360
*/

static	int			ft_read_file(int fd, char *heap, char **stack, char **line)
{
	int				r;
	char			*tmp;

	while ((r = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[r] = '\0';
		if (*stack)
		{
			tmp = *stack;
			*stack = ft_strjoin(tmp, heap);
			free(tmp);
			tmp = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (ft_check_lines(stack, line))
			break ;
	}
	return (RET_VALUE(r));
}



/*
 ** Reads a file line by line.
 ** First parameter is the file descriptor used to read, second parameter 
 ** is the adress of pointer to a character that will be used to save
 ** the line read from the file descriptor. 
 ** Returns -1 error, 0 rear completed, 1 line read. 
 ** Functions allowed: libft, read(), malloc() and free().
 ** Bonus: one single static variable, use t_list.
*/

int		get_next_line(const int fd, char **line)
{
	int r;
	static char	*str;
	
	




}
