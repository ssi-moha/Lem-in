/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:35:56 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/03 10:25:55 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*create_path(t_inf inf)
{
	t_link	*tmp;
	t_link	*tmp2;
	int		i;
	int		j;

	tmp = NULL;
	i = 1;
	j = 0;
	while (i <= inf.ants)
	{
		new_link(inf.start, &tmp);
		tmp2 = tmp;
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->lem = i;
		i++;
	}
	return (tmp);
}

t_room		*list_split(char *path)
{
	t_room	*room;
	t_room	*tmp;
	char	*stk;
	int		i;

	i = 0;
	room = NULL;
	while (path[i])
	{
		stk = ft_strcdup(path + i, ' ');
		new_room(stk, &room);
		free(stk);
		tmp = room;
		while (tmp->next)
			tmp = tmp->next;
		tmp->visit = 0;
		while (!is_space(path[i]) && path[i])
			i++;
		if (path[i])
			i++;
	}
	return (room);
}

int			check_ants(t_room *room, t_inf inf)
{
	t_room *tmp;

	tmp = room;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->visit == inf.ants)
		return (1);
	return (0);
}

void		aff_move(t_room *tmp, t_link *tmp2)
{
	char *stk;

	tmp->visit--;
	tmp->next->visit++;
	stk = tmp2->room;
	tmp2->room = ft_strdup(tmp->next->name);
	free(stk);
	ft_putchar('L');
	ft_putnbr(tmp2->lem);
	ft_putchar('-');
	ft_putstr(tmp2->room);
	ft_putchar(' ');
}

void		take_path(t_inf inf)
{
	t_room *path;
	t_link *ants;
	t_room *tmp;
	t_link *tmp2;

	path = list_split(inf.path);
	ants = create_path(inf);
	tmp = path;
	tmp2 = ants;
	while (!check_ants(path, inf))
	{
		tmp2 = ants;
		while (tmp2)
		{
			tmp = path;
			while (ft_strcmp(tmp->name, tmp2->room))
				tmp = tmp->next;
			if (tmp->next && (!tmp->next->visit
						|| !ft_strcmp(tmp->next->name, inf.end)))
				aff_move(tmp, tmp2);
			tmp2 = tmp2->next;
		}
		ft_putchar('\n');
	}
	free_both(&path, &ants);
}
