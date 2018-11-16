/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:17:03 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:17:33 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void		write_bonus_erreur(char *str)
{
	ft_putstr("ft_nm: Unknown command line argument '");
	ft_putstr(str);
	ft_putendl("'.");
	exit(-1);
}

void		init_struct_bonus_nm(t_all *all)
{
	all->bonus_a = 0;
	all->bonus_g = 0;
	all->bonus_p = 0;
	all->bonus_r = 0;
}

void		parse_nm_bonus(t_all *all, char **av, int ac)
{
	int		i;
	int		t;

	i = 0;
	while (++i < ac)
		if (av && av[i] && av[i][0] == '-')
		{
			all->ac--;
			t = 0;
			while (av[i][++t])
			{
				if (av[i][t] == 'A')
					all->bonus_a = 1;
				else if (av[i][t] == 'g')
					all->bonus_g = 1;
				else if (av[i][t] == 'p')
					all->bonus_p = 1;
				else if (av[i][t] == 'r')
					all->bonus_r = 1;
				else
					write_bonus_erreur(av[i]);
			}
			if (t == 1)
				write_bonus_erreur(av[i]);
		}
}

int			bonus_p_sort(t_all *all, t_cmd **tmp, t_cmd **tmp2)
{
	if (all->bonus_p)
	{
		while ((*tmp) && (*tmp)->next)
			(*tmp) = (*tmp)->next;
		(*tmp)->next = (*tmp2);
		(*tmp2)->next = NULL;
		return (1);
	}
	return (0);
}
