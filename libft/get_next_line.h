/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:02:10 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/05 18:24:33 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct	s_gnllst
{
	char			*string;
	int				descriptor;
	int				ofs;
	struct s_gnllst	*next;
}				t_gnllst;

int				get_next_line(const int fd, char **line);
unsigned long	ft_strlen(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_findchr(const char *str, char c);

#endif
