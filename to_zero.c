/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:01:52 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/23 19:36:36 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	to_zero(t_room *room)
{
	t_room *tmp;

	if (room)
		tmp = room;
	while (tmp)
	{
		tmp->visit = 0;
		tmp = tmp->next;
	}
}
