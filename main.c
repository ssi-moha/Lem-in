/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:43:53 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/27 12:00:42 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_inf inf;
	t_room *room;
	t_room *tmp;
	t_link *tmp2;
	char *path;
	int i = 0;
	int j = 0;

	room = NULL;
	inf.link = NULL;
	path = NULL;
	if (argc != 2)
		exit(0);
	room = read_input(argv[1], &inf);
	tmp = room;
	tmp2 = inf.link;
	inf.tab = set_tab(inf, room);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, inf.start))
			break ;
		tmp = tmp->next;
	}
	printf("test\n");
	printf("start :%s\n", tmp->name);
	//tmp->visit = 1;
	search_path(&inf, NULL, tmp, room);
	to_zero(room);
	take_path(inf, room);
	while (room)
	{
		printf("name : %s\nx : %d\ny : %d\npos : %d\n", room->name, room->x, room->y, room->pos);
		room = room->next;
	}
	while (inf.link)
	{
		printf("link : %s\n", inf.link->room);
		inf.link = inf.link->next;
	}
	printf("start : %s\nend : %s\n", inf.start, inf.end);
	printf("ants : %d\n", inf.ants);
	while (i < inf.nb_rooms)
	{
		j = 0;
		while (j < inf.nb_rooms)
		{
			printf("%d", inf.tab[i][j]);
			j++;
		}
			printf("\n");
		i++;
	}
	printf("inf : %s\n", inf.path);
	if (inf.start)
		free(inf.start);
	if (inf.end)
		free(inf.end);
	free_tab(inf.tab, inf.nb_rooms);
	free_link(&tmp2);
	free_rooms(&tmp);
}
