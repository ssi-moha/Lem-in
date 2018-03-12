/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:49:46 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/09 09:53:25 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		pars_big(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (!is_space(s1[i]) && s1[i])
		i++;
	while (!is_space(s2[j]) && s2[j])
		j++;
	if (j > i)
		return (j);
	return (i);
}

int		check_double(t_room **room, char *str)
{
	t_room *tmp;

	if (!*room)
		return (1);
	tmp = *room;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, str, pars_big(tmp->name, str)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
