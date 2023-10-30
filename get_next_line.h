/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:13:51 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/30 20:37:12 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
//UTILS
char	*readfile(int fd);
char	*next_line(char *aux);
#endif