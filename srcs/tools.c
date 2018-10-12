#include "../includes/nmotool.h"


int			check_corrompu(t_all *all, void *ptr)
{
	if ((void*)(all->ptr + all->file_stat.st_size) < ptr)
	{
		ft_putendl_fd("fichier corrompu.", 2);
		return (1);
	}
	return (0);
}

void		hexx(unsigned long long int v, char *res, int *i)
{
	char	base[17];

	ft_strcpy(base, "0123456789abcdef\0");
	if (16 <= v)
		hexx(v / 16, res, i);
	res[(*i)++] = base[ABS(v % 16)];
}

char		*llx(unsigned long long int value)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * 100)))
		return (NULL);
	hexx(value, res, &i);
	res[i] = 0;
	return (res);
}
