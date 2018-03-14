/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:04:05 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 10:07:05 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			int_valid(long long i)
{
	if (i > INT_MAX)
		return (0);
	if (i < INT_MIN)
		return (0);
	return (1);
}

int			get_xy(t_room **room, char *str)
{
	int			i;
	t_room		*tmp;
	static int num = 0;

	i = 0;
	new_room(str, room);
	tmp = *room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->x = 5;
	while (!is_space(str[i]) && str[i])
		i++;
	while (is_space(str[i]) && str[i])
		i++;
	tmp->x = ft_atoi(str + i);
	while (!is_space(str[i]) && str[i])
		i++;
	while (is_space(str[i]) && str[i])
		i++;
	tmp->y = ft_atoi(str + i);
	tmp->pos = num++;
	tmp->visit = 0;
	if (!int_valid(tmp->x) || !int_valid(tmp->y))
		exit(error_mess("X OR Y SIZE TOO BIG"));
	return (1);
}
