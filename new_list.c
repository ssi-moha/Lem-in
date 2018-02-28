

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
