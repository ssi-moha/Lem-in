/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:19:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/09 10:16:42 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_stk(char **stk)
{
	if (*stk)
		free(*stk);
	return (0);
}

int		is_room(t_room *room, char *stk)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (!ft_strcmp(stk, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		check_link(char *str, t_room *room)
{
	int		i;
	t_room	*check;
	char	*tmp;
	char	*stk;

	if (!room)
		return (0);
	check = room;
	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			return (0);
		i++;
	}
	stk = ft_strcdup(str, '-');
	if (!is_room(room, stk))
		return (free_stk(&stk));
	check = room;
	tmp = ft_strchr(str, '-');
	if (!tmp || tmp[0] != '-')
		return (free_stk(&stk));
	if (!ft_strcmp(tmp + 1, stk))
		return (free_stk(&stk));
	return (free_stk(&stk) + 1);
}
