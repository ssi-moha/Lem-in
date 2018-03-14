/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:40:42 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 12:48:21 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*del_last(char *path)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == ' ')
			j = i;
		i++;
	}
	if (j == 0)
		return (NULL);
	new = ft_strndup(path, j);
	free(path);
	return (new);
}

void	alloc_path(char **path, char *next)
{
	char *new;

	new = *path;
	*path = ft_strjoin(*path, " ");
	free(new);
	new = *path;
	*path = ft_strjoin(*path, next);
	free(new);
}

int		free_new(char **path)
{
	char *new;

	new = *path;
	*path = del_last(ft_strdup(*path));
	free(new);
	return (-1);
}

int		inc_weight(t_room *tmp, t_inf *inf, t_room *next, int *weight)
{
	(*inf).tab[next->pos][tmp->pos] = *weight;
	(*inf).tab[tmp->pos][next->pos] = *weight;
	return (1);
}

int		search_path(t_inf *inf, t_room *prev, t_room *next, t_room *begin_list)
{
	int			j;
	static char	*path;
	static int	weight = 1;
	t_room		*tmp;

	tmp = begin_list;
	!path ? path = ft_strdup(next->name) : alloc_path(&path, next->name);
	if (!ft_strcmp((*inf).end, next->name))
	{
		if (!(*inf).path || path_len((*inf).path) > path_len(path))
			stk_path(inf, path);
		return (0);
	}
	j = -1;
	while (++j < (*inf).nb_rooms)
		if (inf->tab[next->pos][j] > 0 && (inf->tab[next->pos][j] == 1 || weight
		< (*inf).tab[next->pos][j]) && (!prev || prev->pos != j) && j != ret_start(begin_list, inf))
		{
			while (tmp->pos != j)
				tmp = tmp->next;
			weight += inc_weight(tmp, inf, next, &weight);
			if (!search_path(inf, next, tmp, begin_list))
				weight += free_new(&path);
		}
	return (0);
}
