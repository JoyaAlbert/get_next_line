/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:53:19 by joya              #+#    #+#             */
/*   Updated: 2023/11/01 16:23:14 by ajoya-pi         ###   ########.fr       */
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
	printf("\n%s", aux);
	return (line);
}
char	*readfile(int fd)
{
	char		*aux;
	static char	*line;
	int			size;
	int			a;

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
		printf("%s", aux);
		size = a + size;
	}
	line = fill_line(size + 1, aux);
	free(aux);
	return (line);
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
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
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

