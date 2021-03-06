/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:43:59 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/02 19:36:09 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_rooms(t_room **room)
{
	if (!*room)
		return ;
	while (*room)
	{
		free((*room)->name);
		free(*room);
		*room = (*room)->next;
	}
}

void	free_link(t_link **link)
{
	if (!*link)
		return ;
	while (*link)
	{
		free((*link)->room);
		free(*link);
		*link = (*link)->next;
	}
}
