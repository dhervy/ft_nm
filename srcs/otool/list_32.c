#include "../../includes/nmotool.h"

int		first_add_list_32(t_cmd **begin, t_all *all, struct nlist *nlist)
{
	(*begin) = (t_cmd*)malloc(sizeof(t_cmd));
	(*begin)->name = ft_strdup((all->stroff + nlist->n_un.n_strx));
	find_type_32(all, (*begin), nlist);
	(*begin)->value = nlist->n_value;
	(*begin)->next = NULL;
	return (1);
}

int		init_add_list_32(t_cmd **begin, struct nlist *nlist, t_all *all)
{
	if (nlist->n_type & N_STAB)
		return (1);
	if (((*begin) == NULL) && first_add_list_32(begin, all, nlist))
		return (1);
	return (0);
}

void	add_list_32(t_cmd **begin, struct nlist *nlist, t_all *all)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;
	t_cmd	*tmp3;

	if (init_add_list_32(begin, nlist, all) == 1)
		return ;
	init_add_list(begin, &tmp, &tmp2, &tmp3);
	while (tmp->next && (ft_strcmp(tmp->name,\
		(all->stroff + nlist->n_un.n_strx)) < 0))
	{
		tmp3 = tmp;
		tmp = tmp->next;
	}
	tmp2 = (t_cmd*)malloc(sizeof(t_cmd));
	tmp2->name = ft_strdup((all->stroff + nlist->n_un.n_strx));
	find_type_32(all, tmp2, nlist);
	tmp2->value = nlist->n_value;
	if (bonus_p_sort(all, &tmp, &tmp2) == 1)
		return ;
	if (ft_strcmp(tmp->name, (all->stroff + nlist->n_un.n_strx)) > 0)
		sort_lst(begin, &tmp, &tmp2, &tmp3);
	else if (shearch_same_name(begin, tmp2) == 1)
		return ;
	else
		sort_lst2(&tmp, &tmp2);
}