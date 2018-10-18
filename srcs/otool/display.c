#include "../../includes/nmotool.h"

void		display_name(t_all *all)
{
	if (all->ac > 2 && !all->bonus_a)
	{
		ft_putstr("\n");
		ft_putstr(all->name);
		ft_putstr(":\n");
	}
}

void		display_lst_addr(t_all *all, t_cmd *tmp)
{
	char	*tmp2;
	int		i;

	tmp2 = NULL;
	if (all->bonus_a == 1)
	{
		ft_putstr(all->name);
		ft_putstr(": ");
	}
	if (ft_strcmp(tmp->type, "U"))
	{
		i = -1;
		if (tmp->value)
		{
			tmp2 = llx(tmp->value);
			while ((ft_strlen(tmp2) + ++i) < (all->cpu == 32 ? 8 : 16))
				ft_putchar('0');
			ft_putstr(tmp2);
			free(tmp2);
		}
		else
			ft_putstr((all->cpu == 32 ? "00000000" : "0000000000000000"));
	}
	else
		ft_putstr((all->cpu == 64 ? "                " : "        "));
}

void		display_lst_norm(t_cmd *tmp)
{
	ft_putstr(" ");
	if (tmp->type)
		ft_putstr(tmp->type);
	ft_putstr(" ");
	if (tmp->name)
		ft_putstr(tmp->name);
	ft_putchar('\n');
}

void	display_reverse(t_cmd *tmp, t_all *all)
{
	if (tmp && tmp->next)
		display_reverse(tmp->next, all);
	if (tmp && (all->bonus_g == 0 || (all->bonus_g == 1 && tmp && tmp->type && \
		tmp->type[0] && tmp->type[0] >= 65 && tmp->type[0] <= 90)))
	{
		display_lst_addr(all, tmp);
		display_lst_norm(tmp);
	}
}

void		display_lst(t_cmd **cmds, t_all *all)
{
	t_cmd	*tmp;

	tmp = *cmds;
	if (all->bonus_r)
		display_reverse(tmp, all);
	else
	{
		while (tmp)
		{
			if (all->bonus_g == 0 || (all->bonus_g == 1 && tmp && tmp->type && \
					tmp->type[0] && tmp->type[0] >= 65 && tmp->type[0] <= 90))
			{
				display_lst_addr(all, tmp);
				display_lst_norm(tmp);
			}
			tmp = tmp->next;
		}
	}
	// free_lst(cmds);
}
