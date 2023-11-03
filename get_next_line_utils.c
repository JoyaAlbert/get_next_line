/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:53:19 by joya              #+#    #+#             */
/*   Updated: 2023/11/03 14:27:25 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*fill_line(int size, char *aux)
{
	static char	*line;
	int	i;

	i = 0;
	line = malloc(sizeof(char) * size);
	if(line == NULL)
		return (NULL);
	while (i < size)
	{
		line[i] = aux[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
/**
char	*readfile(int fd)
{
	char		*aux;
	static char	*line;
	int			size;
	int			a;
	char		*puta;

	size = 0;
	aux = malloc(1024);
	if (aux == NULL)
		return (NULL);
	a = 1;
	while (aux[a - 1] != '\0' || a == 1)
	{
		a = read (fd, aux, BUFFER_SIZE);
		if (a == -1)
			return (NULL);
		size = a + size;
	}
	puta[size] = '\0';
	printf("%s", puta);

	line = fill_line(size + 1, aux);
	free(aux);
	return (line);
}*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

unsigned int	ft_strladd(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j <= size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i - 1] = '\0';
	return (ft_strlen(src));
}

char	*readfile(int fd)
{
	char	*aux;
	char	*temp;
	char	*lines;
	int	size;
	int	a;

	a = 0;
	size = 0;
	aux = malloc(1024);
	temp = malloc(1024);
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
			free(temp);
			return (lines);
		}
		aux[ft_strlen(aux)] = '\0';
		size = a + size;
	}
	//return (lines);
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

char	*delete(char *aux)
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
	//ft_memset(nlines + j, '\0', i);
	return (nlines);
}

