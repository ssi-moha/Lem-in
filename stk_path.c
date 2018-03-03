/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 18:21:52 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/02 18:50:10 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	stk_path(t_inf *inf, char *path)
{
	char *new;

	new = inf->path;
	(*inf).path = ft_strdup(path);
	if (new != NULL)
		free(new);
}
