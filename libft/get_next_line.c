/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:00:49 by mvogee            #+#    #+#             */
/*   Updated: 2016/11/05 15:20:24 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*extend_line(char *s1, char *s2, int bytes_read, int len)
{
	char			hold[len];
	int				count;

	count = 0;
	while (count < len)
	{
		hold[count] = s1[count];
		count++;
	}
	hold[len] = '\0';
	if (s1)
		free(s1);
	s1 = NULL;
	s1 = (char*)malloc(sizeof(char) * bytes_read + len + 1);
	while (hold[count - len])
	{
		s1[count - len] = hold[count - len];
		count++;
	}
	while (count - (len * 2) < bytes_read)
	{
		s1[count - len] = s2[count - (len * 2)];
		count++;
	}
	return (s1);
}

char		*read_entire_fd(int fd)
{
	char			tmp[BUFF_SIZE];
	int				bytes_read;
	char			*retstr;
	int				len;

	len = 0;
	retstr = NULL;
	if (fd < 0)
		return (NULL);
	bytes_read = read(fd, tmp, BUFF_SIZE);
	if (bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		retstr = extend_line(retstr, tmp, bytes_read, len);
		len += bytes_read;
		bytes_read = read(fd, tmp, BUFF_SIZE);
	}
	if (retstr)
		retstr[len] = '\0';
	return (retstr);
}

t_gnllst	*new_fd(int fd, char *str, int job, t_gnllst *freeme)
{
	t_gnllst			*node;

	if (job == 1)
	{
		node = (t_gnllst*)malloc(sizeof(t_gnllst));
		node->descriptor = fd;
		node->string = str;
		node->next = NULL;
		node->ofs = ft_strlen(str);
		return (node);
	}
	node = freeme;
	while (freeme->descriptor != fd)
	{
		node = freeme;
		freeme = freeme->next;
	}
	node->next = (node->descriptor !=
		freeme->descriptor ? freeme : node->next);
	freeme->string -= freeme->ofs;
	free(freeme->string);
	freeme->string = "\0";
	freeme->ofs = 0;
	return (node);
}

int			do_gnl(char *str, char **line)
{
	int		ret;
	int		new_line;

	ret = 1;
	if (*str == 0)
		return (0);
	new_line = ft_findchr(str, '\n');
	if (new_line < 0 && str[0] != '\n')
		new_line = ft_findchr(str, '\0');
	*line = ft_strsub(str, 0, new_line);
	if (!line)
		return (-1);
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnllst	*fd_lst;
	t_gnllst		*head;
	int				shift;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!fd_lst)
		fd_lst = new_fd(fd, read_entire_fd(fd), 1, NULL);
	head = fd_lst;
	while (fd_lst->descriptor != fd)
	{
		if (fd_lst->next == NULL)
			fd_lst->next = new_fd(fd, read_entire_fd(fd), 1, NULL);
		fd_lst = fd_lst->next;
	}
	if (fd_lst->string == NULL)
		return (-1);
	ret = do_gnl(fd_lst->string, line);
	shift = (ft_findchr(fd_lst->string, '\n') < 0 ?
	ft_findchr(fd_lst->string, '\0') - 1 : ft_findchr(fd_lst->string, '\n'));
	fd_lst->string += shift + 1;
	head = ((ret == 0 && fd_lst->ofs != 0) ? new_fd(fd, NULL, 0, head) : head);
	fd_lst = head;
	return (ret);
}
