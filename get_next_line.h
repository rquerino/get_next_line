/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:39:37 by rquerino          #+#    #+#             */
/*   Updated: 2019/05/18 12:41:09 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <libft/libft.h>
# include <stdlib.h>
# include <unistd.h>


# define BUFF_SIZE 32

int		get_next_line(const int fd, char **line);

#endif
