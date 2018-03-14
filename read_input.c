/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:02:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 10:03:21 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*init_func(t_inf *inf, char **prev)
{
	*prev = ft_strdup("");
	(*inf).start = NULL;
	(*inf).end = NULL;
	(*inf).link = NULL;
	(*inf).nb_rooms = 0;
	return (NULL);
}

t_room	*ret_room(char **prev, char **str, t_room *room)
{
	free(*str);
	free(*prev);
	return (room);
}

void	put_str(char **str)
{
	*str != NULL ? ft_strdel(str) : (*str);
	get_next_line(0, str);
	ft_putendl(*str);
}

void	free_prev(char **prev, char **str)
{
	free(*prev);
	*prev = *str;
}

t_room	*read_input(t_inf *inf)
{
	char	*str;
	char	*prev;
	t_room	*room;

	str = NULL;
	room = init_func(inf, &prev);
	while (!str || str[0] == '#')
		put_str(&str);
	(*inf).ants = ft_atoi(str);
	((*inf).ants < 1) ? exit(error_mess(NULL)) : ft_strdel(&str);
	while (get_next_line(0, &str) > 0)
	{
		ft_putendl(str);
		if (!get_start(inf, prev, &str, room))
			return (ret_room(&prev, &str, room));
		if (str[0] != '#' && check_format(str, room))
			(*inf).nb_rooms += get_xy(&room, str);
		else if (check_link(str, room))
			get_link(inf, str);
		else if (str[0] != '#')
			return (ret_room(&prev, &str, room));
		free_prev(&prev, &str);
	}
	ft_strdel(&str);
	return (room);
}
