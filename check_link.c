


#include "lem_in.h"

int		free_stk(char **stk)
{
	if (*stk)
		free(*stk);
	return (0);
}

int	check_link(char *str, t_room *room)
{
	int i;
	t_room *check;
	char *tmp;
	char *stk;

	if (!room)
		return (0);
	check = room;
	i = 0;
	while (str[i])
	{
		if (is_space(str[i]))
			return (0);
		i++;
	}
	stk = ft_strcdup(str, '-');
	//	printf("stk %s\n, check %s\n", stk, check->name);
	//	while (ft_strcmp(stk, check->name) && check)
	//	{
	//		printf("test\n");
	//		check = check->next;
	//	}
	//	if (!check)
	//		return (0);
	check = room;
	tmp = ft_strchr(str, '-');
	//	while (ft_strcmp(tmp, check->name) && check)
	//		check = check->next;
	//	if (!check)
	//		return (0);
	if (!tmp || tmp[0] != '-')
		return (free_stk(&stk));
	if (!ft_strcmp(tmp + 1, stk))
		return (free_stk(&stk));
	return (free_stk(&stk) + 1);
}
