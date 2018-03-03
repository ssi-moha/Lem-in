/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:14:56 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/02 17:15:07 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	new_link(char *str, t_link **old)
{
	t_link *tmp;
	t_link *tmp2;

	tmp = NULL;
	tmp2 = *old;
	if (!(tmp = (t_link*)malloc(sizeof(t_link))))
		return ;
	tmp->room = ft_strdup(str);
	tmp->next = NULL;
	if (!*old)
		*old = tmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
}
