/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/11/01 15:54:46 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *nlines;
	char		*line;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = readfile(fd);
	//printf("%s", aux);
	if (aux == NULL)
	{
		free(aux);
		return (aux);
	}
	if (nlines == NULL)
		nlines = aux;
	line = next_line(nlines);
	nlines = delete(nlines);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	//for(int i = 0; i < 3; i++)
	get_next_line(fd);
	return 0;
}
