/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:51:17 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/02 17:06:01 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_xy(t_room *room, char *str)
{
	t_room	*tmp;
	char	*stk;
	int		x;
	int		y;

	if (!room)
		return (1);
	tmp = room;
	stk = ft_strchr(str, ' ');
	x = ft_atoi(stk + 1);
	stk = ft_strrchr(str, ' ');
	y = ft_atoi(stk + 1);
	while (tmp)
	{
		if (x == tmp->x && y == tmp->y)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
