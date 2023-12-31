/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:14:56 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/11/03 16:36:32 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readfile(int fd, int size, char *aux)
{
	char	temp[1024];
	char	*lines;
	int		a;

	while (1)
	{	
		a = read(fd, aux, BUFFER_SIZE);
		if (a == -1)
			return (NULL);
		if (size == 0)
			ft_strlcpy(temp, aux, a);
		else
			ft_strladd(temp, aux, a);
		if (aux[a - 1] == '\0')
		{
			size = a + size;
			lines = fill_line(size + 1, temp);
			free(aux);
			return (lines);
		}
		aux[ft_strlen(aux)] = '\0';
		size = a + size;
	}
}

char	*text(int fd)
{
	char	*aux;
	char	*lines;
	int		size;

	size = 0;
	aux = malloc(1024);
	lines = readfile(fd, size, aux);
	return (lines);
}

char	*next_line(char *aux)
{
	int		i;
	char	*line;

	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
	{
		line[i] = aux[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*delete_first(char *aux)
{
	int		i;
	int		j;
	char	*nlines;

	j = 0;
	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	nlines = malloc((int)ft_strlen(aux) - i);
	while (j < (int)ft_strlen(aux) - i)
	{
		nlines[j] = aux[j + i + 1];
		j++;
	}
	nlines[j] = '\0';
	return (nlines);
}

char	*get_next_line(int fd)
{
	static char	*nlines;
	char		*line;
	char		*aux;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = text(fd);
	if (aux == NULL)
	{
		free(aux);
		return (aux);
	}
	if (nlines == NULL)
		nlines = aux;
	line = next_line(nlines);
	nlines = delete_first(nlines);
	return (line);
}
