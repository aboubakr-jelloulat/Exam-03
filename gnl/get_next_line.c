/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 00:13:15 by ajelloul          #+#    #+#             */
/*   Updated: 2025/03/15 00:13:16 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int byte, i = 0;
	char c, *buffer = (char *)malloc(10000);
	if (!buffer) return NULL;

	if (fd < 0) return NULL;
	
	for (byte = read(fd, &c, 1); byte > 0 ; i++)
		buffer[i] = c,   byte = (c == '\n' || c == EOF) ? 0 : read(fd, &c, 1);
	if (i == 0 || byte < 0)
		return (free(buffer), NULL);
	return (buffer[i] = '\0', buffer);
}

/*
int main(void)
{
    int     fd,  i = 0;
    char    *buffer;
    

	for (int fd = open("file.txt", O_RDONLY) ,i = 0; i < 100; i++)
	{
		buffer = get_next_line(fd);
        printf("line %d : %s\n",i , buffer);
		if (!buffer)
			break;
	}

    return (0);
}
*/
