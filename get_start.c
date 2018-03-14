/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 09:45:23 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 10:46:51 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		skip_comment(char *prev, char **str)
{
	char *tmp;
	int ret;

	tmp = NULL;
	ret = 1;
	if ((!ft_strcmp("##start", prev) || !ft_strcmp("##end", prev)) &&
			*str[0] == '#')
	{
		while (*str[0] == '#' && ret > 0)
		{
			tmp = *str;
			ret = get_next_line(0, str);
			if (tmp && *str[0] != '#')
			ft_strdel(&tmp);
		}
		return (1);
	}
	return (0);

}

int	get_start(t_inf *inf, char *prev, char **str, t_room *room)
{
	skip_comment(prev, str);
	if (!ft_strcmp("##start", prev) && check_format(*str, room))
	{
		if ((*inf).start)
			return (0);
		(*inf).start = ft_strcdup(*str, ' ');
	}
	else if (!ft_strcmp("##end", prev) && check_format(*str, room))
	{
		if ((*inf).end)
			return (0);
		(*inf).end = ft_strcdup(*str, ' ');
	}
	else if (!ft_strncmp("##", prev, 2))
	{
		return (1);
	}
	return (1);
}
