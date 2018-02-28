/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:02:58 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/14 14:52:34 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_path(t_inf inf, t_room *room)
{
	t_room *tmp;
	t_link *tmp2;
	char *current;
	char *path;

	tmp = room;
	tmp2 = inf.link;
	current = inf.start;
	while (tmp2)
	{
		if (ft_strstr(tmp2->room, current) != NULL)
			tmp 
		tmp2 = tmp->next;
	}
}
