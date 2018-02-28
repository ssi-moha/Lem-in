/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:02:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/26 18:44:05 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*read_input(char *file_name, t_inf *inf)
{
	int		fd;
	char *str;
	char *prev;
	int i;
	t_room *room;

	prev = ft_strdup("");
	fd = open(file_name, O_RDONLY);
	(*inf).start = NULL;
	(*inf).end = NULL;
	(*inf).link = NULL;
	(*inf).nb_rooms = 0;
	room = NULL;
	while (!str || str[0] == '#')
	{
		if (str)
			free (str);
		get_next_line(fd, &str);
	}
	(*inf).ants = ft_atoi(str);
	if ((*inf).ants < 1)
		return (0);
	free(str);
	while (get_next_line(fd, &str) > 0)
	{
		if (!get_start(inf, prev, str, room))
		{
			free(str);
			free(prev);
			return (room);
		}
		if (str[0] != '#' && check_format(str, room))
		{
			(*inf).nb_rooms++;
			get_xy(&room, str);
		}
		else if (check_link(str, room))
			get_link(inf, str);
		else if (str[0] != '#')
		{
			free(prev);
			free(str);
			return (room);
		}
		free (prev);
		prev = str;
	}
	free(str);
	return (room);
}
