/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:49:46 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/16 14:58:12 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int check_double(t_room **room, char *str)
{
	t_room *tmp;

	if (!*room)
		return (1);
	tmp = *room;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, str, ft_strclen(str, ' ')))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
