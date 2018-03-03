/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:19:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/02 17:19:08 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_stk(char **stk)
{
	if (*stk)
		free(*stk);
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
	check = room;
	tmp = ft_strchr(str, '-');
	if (!tmp || tmp[0] != '-')
		return (free_stk(&stk));
	if (!ft_strcmp(tmp + 1, stk))
		return (free_stk(&stk));
	return (free_stk(&stk) + 1);
}
