/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:35:56 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/28 18:01:29 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link		*create_path(t_inf inf)
{
	t_link *tmp;
	int i;
	int j;

	tmp = NULL;
	i = 1;
	j = 0;
	while (i <= inf.ants)
	{
		new_link(inf.start, &tmp);
		tmp->lem = i;
		i++;
	}
	return (tmp);
}

int		check_ants(t_link *link, t_inf inf)
{
	t_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (tmp->lem == inf.ants && !ft_strcmp(tmp->room, inf.end))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	take_path(t_inf inf, t_room *room)
{
	char **tab;
	t_link *path;
	t_link *tmp;
	int i;
	int j;
	int count;

	i = 1;
	j = 1;
	tab = ft_strsplit(inf.path, ' ');
	path = create_path(inf);
	tmp = path;
	printf("test\n");
	while (tmp)
	{
		printf("%d\n", tmp->lem);
		tmp = tmp->next;
	}
	/*	while (tmp)
	{
		printf("L%d-%s", tmp->lem, tmp->room);
		tmp = tmp->next;
	}
	tmp = path;
	while (!check_ants(path, inf))
	{
		j = count;
		tmp = path;
		while (tmp && tmp->lem <= i)
		{
			while (!ft_strcmp(tmp->room, inf.end))
				tmp = tmp->next;
			if (!tmp)
				break ;
			tmp->room = tab[j];
			printf("L%d-%s", tmp->lem, tmp->room);
			j--;
		}
		if (tab[count + 1])
			count++;
		ft_putchar('\n');
		i++;
	}*/
}
