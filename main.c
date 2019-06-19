/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 14:04:50 by rquerino          #+#    #+#             */
/*   Updated: 2019/06/19 14:17:19 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"
int     main(int ac, char *av[])
{
    char    *line;

/* BASIC TESTS */

/* READ FROM STANDARD INPUT */
    while (get_next_line(0, &line) > 0)
        printf("%s\n", line);
    
/* SINGLE DESCRIPTOR — — — — — — — — — — — — — — — — — — — — — — */
    /*
    int     fd1;
    fd1 = open(av[1], O_RDONLY);
    while (get_next_line(fd1, &line) > 0)
        printf("%s\n", line);
    close(fd1);
    */
/* MULTIPLE FILE DESCRIPTORS — — — — — — — — — — — — — — — — — — — — — — —*/
    /*
    int      fd1;
     int      fd2;
     int      fd3;
     fd1 = open(av[1], O_RDONLY);
     fd2 = open(av[2], O_RDONLY);
     fd3 = open(av[3], O_RDONLY);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd1, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd2, &line), line);
    printf("[%i] $> %s\n", get_next_line(fd3, &line), line);
    close(fd1);
    close(fd2);
    close(fd3);
    */
    (void)ac;
    (void)av;
    return (0);
}
