/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 21:40:42 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/26 20:15:39 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*del_last(char *path)
{
	int i;
	int j;
	char *new;

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

int		check_start(char *start, char *path)
{
	if (ft_strstr(path, start) == NULL)
		return (0);
	return (1);
}

int		search_path(t_inf *inf, t_room *prev, t_room *next, t_room *begin_list)
{
	int j;
	static char *path;
	static int weight = 1;
	t_room *tmp;
	char *new;

	tmp = begin_list;;
	if (!path)
		path = ft_strdup(next->name);
	else
	{
		new = path;
		path = ft_strjoin(path, " ");
		free(new);
		new = path;
		path = ft_strjoin(path, next->name);
		free(new);
	}
	if (!ft_strcmp((*inf).end, next->name))
	{
		printf("PATH %s\n", path);
		if (inf->path)
			printf("%s\n", inf->path);
		if (!(*inf).path || path_len((*inf).path) > path_len(path))
			(*inf).path = ft_strdup(path);
		printf("INF %s\n", inf->path);
		weight = 1;
		return (1);
	}
	j = 0;
	while (j < (*inf).nb_rooms)
	{
		if ((*inf).tab[next->pos][j] && (!prev || prev->pos != j) && (weight >= (*inf).tab[next->pos][j]))
		{
			while (tmp->pos != j)
				tmp = tmp->next;
			(*inf).tab[next->pos][j] = weight;
			weight++;
			search_path(inf, next, tmp, begin_list);
			new = path;
			path = del_last(ft_strdup(path));
			free(new);
		}
		j++;
	}
	return (1);
}
