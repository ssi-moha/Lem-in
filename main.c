/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:43:53 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 10:47:56 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_this(t_inf *inf)
{
	(inf->start != NULL) ? free(inf->start) : (inf->start);
	(inf->end != NULL) ? free(inf->end) : (inf->end);
	(inf->path != NULL) ? free(inf->path) : (inf->path);
}

int		main(int argc, char **argv)
{
	t_inf	inf;
	t_room	*room;
	t_room	*tmp;

	room = NULL;
	inf.link = NULL;
	if (argc > 1 && argv)
		exit(error_mess("use > to read the file\n"));
	room = read_input(&inf);
	!inf.start || !inf.end ? exit(error_mess(NULL)) : (tmp = room);
	inf.tab = set_tab(inf, room);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, inf.start))
			break ;
		tmp = tmp->next;
	}
	search_path(&inf, NULL, tmp, room);
	!inf.path ? exit(error_mess("ERROR : NO VALID PATH FOUND\n")) : (inf.path);
	ft_putchar('\n');
	to_zero(room);
	take_path(inf);
	free_this(&inf);
	free_tab(inf.tab, inf.nb_rooms);
	free_both(&room, &inf.link);
}
