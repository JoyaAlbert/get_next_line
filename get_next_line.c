/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/27 15:43:07 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"
static char * readfile(fd)
{
	char *aux;

	aux = malloc(BUFFER);
	if (read(fd, &aux, BUFFER));
		return (NULL);
	return(aux);
}
char	*get_next_line(int fd)
{
	static char *aux;
	char *line;

	aux = NULL;
	if (aux[BUFFER] != NULL)
	{
		aux = readfile(fd);
		if (aux == NULL)
			return (NULL);
	}

	line = next_line(aux);

}

