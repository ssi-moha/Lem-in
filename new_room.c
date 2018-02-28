/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:39:18 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/01/31 12:45:45 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	new_room(char *str, t_room **old)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = NULL;
	tmp2 = *old;
	if (!(tmp = (t_room*)malloc(sizeof(t_room))))
		return ;
	tmp->name = ft_strcdup(str, ' ');
	tmp->x = 0;
	tmp->y = 0;
	tmp->next = NULL;
	if (!*old)
		*old = tmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next= tmp;
	}
}
