/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:53:19 by joya              #+#    #+#             */
/*   Updated: 2023/10/31 21:59:34 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(int fd)
{
	char		*aux;
	static char	*line;
	int			size;
	int			i;

	i = 0;
	aux = malloc(BUFFER_SIZE + 1);
	if (aux == NULL)
		return (NULL);
	size = read (fd, aux, BUFFER_SIZE);
	if (size > 0)
	{
		line = malloc(sizeof(char) * size);
		while (i < size)
		{
			line[i] = aux[i];
			i++;
		}
		line[i] = '\0';
	}
	free(aux);
	printf("%s", line);
	if (size < 0)
		return (NULL);
	return (line);
}

char	*next_line(char *aux)
{
	int		i;
	char	*line;

	i = 0;
	while (aux[i] != '\n' || aux[i] != '\0')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (aux[i] != '\n' || aux[i] != '\0')
	{
		line[i] = aux[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
