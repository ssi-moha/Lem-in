/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:10:48 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/21 16:44:58 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	free_path(char **tab)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (tab[len])
		len++;
	if (!tab)
		return (0);
	while (i < len)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = (NULL);
	return (0);
}
