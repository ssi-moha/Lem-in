/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:59:20 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/26 18:41:03 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		**allocate_tab(int nb)
{
	int **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	tab = (int**)malloc(sizeof(int*) * nb);
	while (i < nb)
	{
		tab[i] = (int*)malloc(sizeof(int) * nb);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

int		**write_one(int **tab, t_room *room, char *name)
{
	t_room *tmp1;
	t_room *tmp2;
	int i;
	int j;

	tmp1 = room;
	tmp2 = room;
	i = 0;
	j = 0;
	while (tmp1 && ft_strncmp(tmp1->name, name, ft_strclen(name, '-')) != 0)
	{
		i++;
		tmp1 = tmp1->next;
	}
	while (tmp2 && ft_strcmp(tmp2->name, ft_strchr(name, '-') + 1))
	{
		j++;
		tmp2 = tmp2->next;
	}
	if (tmp1 && tmp2 && i != j)
	{
		tab[i][j] = 1;
		tab[j][i] = 1;
	}
	return (tab);
}

int		**set_tab(t_inf inf, t_room *room)
{
	t_link	*tmp;
	t_room	*tmp2;
	int		**tab;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp2 = room;
	tmp = inf.link;
	tab = allocate_tab(inf.nb_rooms);
	while (tmp)
	{
		tab = write_one(tab, room, tmp->room);
		tmp = tmp->next;
	}
	return (tab);
}
