/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/28 09:45:34 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"
static char * readfile(int fd)
{
	char *aux;

	aux = malloc(BUFFER);
	if (read(fd, &aux, BUFFER) == -1);
		return (NULL);
	return(aux);
}

char *next_line(char *aux)
{
	int i;
	char *line;

	i = 0;
	while(aux[i] != '\n' || aux[i] != '\0')
		i++;
	line = malloc(i * sizeof(char));
	if (line == NULL)
		return (NULL);
		i = 0;
	while(aux[i] != '\n' || aux[i] != '\0')
	{
		line[i] = aux[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char *aux;
	char *line;

	aux = NULL;
	if (aux[BUFFER] != '\0')
	{
		aux = readfile(fd);
		if (aux == NULL)
			return (NULL);
	}

	line = next_line(aux);
	free(aux);
	printf("%s", line);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return 0;
}