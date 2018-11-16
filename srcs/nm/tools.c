/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:19:50 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:19:52 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

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

char		*find_cputype(t_all *all, int nb)
{
	if (nb == 7)
		return ("i386):\n");
	else if (nb == 6)
		return ("mc680x0):\n");
	else if (nb == 10)
		return ("mc98000):\n");
	else if (nb == 11)
		return ("hppa):\n");
	else if (nb == 13)
		return ("mc88000):\n");
	else if (nb == 14)
		return ("sparc):\n");
	else if (nb == 15)
		return ("i860):\n");
	else if (nb == 18)
	{
		all->arch_ppc = 1;
		return ("ppc):\n");
	}
	else if (nb == 16777223)
		return ("x86_64):\n");
	return ("unkmow):\n");
}

uint32_t	swap32(uint32_t a)
{
	a = ((a & 0x000000FF) << 24) |
		((a & 0x0000FF00) << 8) |
		((a & 0x00FF0000) >> 8) |
		((a & 0xFF000000) >> 24);
	return (a);
}
