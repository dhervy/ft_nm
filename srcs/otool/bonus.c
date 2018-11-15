#include "../../includes/nmotool.h"

void		write_bonus_erreur(char *str)
{
	ft_putstr("ft_otool: Unknown command line argument '");
	ft_putstr(str);
	ft_putendl("'.");
	exit(-1);
}

void		init_struct_bonus_otool(t_all *all)
{
	all->bonus_d = 0;
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
					write_bonus_erreur(av[i]);
			}
			if (t == 1)
				write_bonus_erreur(av[i]);
		}
	}
}
