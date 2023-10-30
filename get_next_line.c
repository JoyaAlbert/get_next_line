/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/30 20:37:45 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = readfile(fd);
	if (aux == NULL)
	{
		free(aux);
		return (aux);
	}
	//line = next_line(aux);
	return (NULL);
}
/*
int main()
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return 0;
}*/
