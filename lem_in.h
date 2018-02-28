/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:37:18 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/27 13:14:03 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include "get_next_line.h"
# include <limits.h>

typedef struct	s_link
{
	int lem;
	char *room;
	struct s_link *next;
}				t_link;

typedef struct s_room
{
	char *name;
	int x;
	int y;
	int pos;
	int visit;
	struct s_room *next;
}				t_room;

typedef struct	s_inf
{
	char *start;
	char *end;
	int ants;
	t_link *link;
	int **tab;
	char *path;
	int nb_rooms;
}				t_inf;

t_room	*new_elem(char *str, t_room *old);
void	new_room(char *str, t_room **old);
t_room	*read_input(char *file_name, t_inf *inf);
void	free_rooms(t_room **room);
int		get_start(t_inf *inf, char *prev, char *str, t_room *room);
int		is_space(char c);
int		check_format(char *str, t_room *room);
void	get_xy(t_room **room, char *str);
int		check_link(char *str, t_room *room);
void	get_link(t_inf *inf, char *str);
void	new_link(char *str, t_link **old);
int		int_valid(long long i);
int		**set_tab(t_inf inf, t_room *room);
int		check_double(t_room **room, char *str);
int		check_xy(t_room *room, char *str);
int		free_tab(int **tab, int nb);
void	free_link(t_link **link);
int		search_path(t_inf *inf, t_room *prev, t_room *next, t_room *begin_list);
void	cpy_path(t_inf inf, char *path);
int		free_path(char **tab);
int		path_len(char *path);
void	to_zero(t_room *room);
void	take_path(t_inf inf, t_room *room);
#endif
