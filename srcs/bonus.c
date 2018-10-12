#include "../includes/nmotool.h"

void		write_bonus_erreur(char *str, int i)
{
	if (i == 0)
		ft_putstr("ft_nm: Unknown command line argument '");
	else if (i == 1)
		ft_putstr("ft_otool: Unknown command line argument '");
	ft_putstr(str);
	ft_putendl("'.");
	exit(-1);
}

void		init_struct_bonus(t_all *all)
{
	all->bonus_a = 0; // Good
	all->bonus_g = 0; // Good
	all->bonus_p = 0; // Good
	all->bonus_d = 0;
	all->bonus_r = 0; // Good
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
					write_bonus_erreur(av[i], 0);
			}
			if (t == 1)
				write_bonus_erreur(av[i], 1);
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

void		parse_otool_bonus(t_all *all, char **av, int ac)
{
	int		i;
	int		t;

	i = 0;
	while (++i < ac)
	{
		if (av && av[i] && av[i][0] == '-')
		{
			all->ac--;
			t = 0;
			while (av[i][++t])
			{
				if (av[i][t] == 'd')
					all->bonus_d = 1;
				else
					write_bonus_erreur(av[i], 1);
			}
			if (t == 1)
				write_bonus_erreur(av[i], 1);
		}
	}
}