/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:45:23 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/10 13:07:52 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_start(t_inf *inf, char *prev, char *str, t_room *room)
{
	if (!ft_strcmp("##start", prev) && check_format(str, room) && str[0] != '#')
	{
		if ((*inf).start)
			return (0);
		(*inf).start = ft_strcdup(str, ' ');
	}
	else if (!ft_strcmp("##end", prev) && check_format(str, room) && str[0] !=
			'#')
	{
		if ((*inf).end)
			return (0);
		(*inf).end = ft_strcdup(str, ' ');
	}
	else if (!ft_strncmp("##", prev, 2))
	{
		return (1);
	}
	return (1);
}
