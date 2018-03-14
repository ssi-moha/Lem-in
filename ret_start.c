/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:48:47 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 11:55:09 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ret_start(t_room *room, t_inf *inf)
{
	t_room *tmp;

	tmp = room;
	while (tmp && ft_strcmp(inf->start, tmp->name))
	{
		tmp = tmp->next;
	}
	return (tmp->pos);
}
