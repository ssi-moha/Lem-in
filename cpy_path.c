/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:40:11 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/21 16:48:03 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	cpy_path(t_inf inf, char *path)
{
	static int size = 1;
	char **tmp;

	if (inf.path)
		tmp = inf.path;
	inf.path = (char **)malloc(sizeof(char *) * size);
	if (tmp)
		free_path(tmp);
}
