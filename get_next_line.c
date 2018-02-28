/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:01:29 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/28 14:49:11 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static char			*display_file(const int fd)
{
	char	*tmp;
	char	*file_content;
	char	*buf;
	int		ret;

	file_content = (char*)ft_memalloc(sizeof(char) * 1);
	if (!file_content)
		return (NULL);
	buf = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!file_content)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = file_content;
		file_content = ft_strjoin(file_content, buf);
		ft_bzero(buf, BUFF_SIZE + 1);
		free(tmp);
	}
	if (ret == -1)
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	return (file_content);
}

static int			nextline(char *file_content)
{
	int i;

	i = 0;
	while (file_content[i] && file_content[i] != '\n')
		i++;
	if (file_content[i] == '\n')
		i++;
	return (i);
}

static int			newfd(const int fd, t_list **file)
{
	t_list			*tmp;
	char			*str;

	if (!(str = display_file(fd)))
		return (-1);
	if (!(tmp = ft_lstnew(str, ft_strlen(str) + 1)))
		return (-1);
	tmp->content_size = fd;
	if (file)
	{
		tmp->next = *file;
		*file = tmp;
	}
	else
		*file = tmp;
	free(str);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*tmp;
	char			*str;

	tmp = file;
	while (tmp)
		if (fd == (int)tmp->content_size)
		{
			str = tmp->content;
			if (ft_strlen(tmp->content) == 0)
				return (0);
			*line = ft_strcdup(tmp->content, '\n');
			tmp->content = ft_strdup(tmp->content + nextline(tmp->content));
			free(str);
			return (1);
		}
		else
			tmp = tmp->next;
	if (newfd(fd, &file) == -1)
		return (-1);
	str = file->content;
	*line = ft_strcdup(file->content, '\n');
	file->content = ft_strdup(file->content + nextline(file->content));
	free(str);
	return (1);
}
