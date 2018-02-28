/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:55:08 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/16 20:58:11 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		str_digit(char *tmp)
{
	int i;

	i = 1;
	if (tmp[i] == '-')
		i++;
	while (tmp[i] != ' ' && tmp[i])
	{
		if (!ft_isdigit(tmp[i]) && tmp[i])
			return (0);
		i++;
	}
	return (1);
}

int		check_format(char *str, t_room *room)
{
	int i;
	char *tmp;

	i = 0;
	if (!check_double(&room, str))
		return (0);
	while (!is_space(str[i]) && str[i])
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	if (ft_strchr(str, ' ') == ft_strrchr(str, ' '))
		return (0);
	tmp = ft_strchr(str, ' ');
	i = 1;
	if (!str_digit(tmp) || !int_valid(ft_atoi(tmp + i)))
		return (0);
	tmp = ft_strrchr(str, ' ');
	i = 1;
	if (!str_digit(tmp)|| !int_valid(ft_atoi(tmp + i)))
		return (0);
	if (!check_xy(room, str))
		return (0);
	return(1);
}

/*int 	main()
  {
  printf("%d\n", check_format("sin 15 8"));  
  }*/
