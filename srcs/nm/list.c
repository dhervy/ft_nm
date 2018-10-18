#include "../../includes/nmotool.h"

void	init_add_list(t_cmd **begin, t_cmd **tmp, t_cmd **tmp2, t_cmd **tmp3)
{
	*tmp2 = NULL;
	*tmp3 = NULL;
	*tmp = *begin;
}

void		sort_lst(t_cmd **begin, t_cmd **tmp, t_cmd **tmp2, t_cmd **tmp3)
{
	(*tmp2)->next = *tmp;
	if (*tmp3 == NULL)
		*begin = *tmp2;
	else
		(*tmp3)->next = *tmp2;
}

void		sort_lst2(t_cmd **tmp, t_cmd **tmp2)
{
	(*tmp2)->next = !(*tmp)->next ? NULL : (*tmp)->next;
	(*tmp)->next = *tmp2;
}

void		init_shearch_same_name(t_cmd **begin, t_cmd **tmp, t_cmd **tmp2)
{
	(*tmp) = *begin;
	(*tmp2) = NULL;
}

int			shearch_same_name(t_cmd **begin, t_cmd *this)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	init_shearch_same_name(begin, &tmp, &tmp2);
	while (tmp->next && ft_strcmp(tmp->name, this->name))
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (!ft_strcmp(tmp->name, this->name))
	{
		while (tmp && this && (!ft_strcmp(tmp->name, this->name))\
		&& this->value > tmp->value)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		this->next = tmp;
		if (tmp2)
			tmp2->next = this;
		else
			*begin = this;
		return (1);
	}
	return (0);
}
