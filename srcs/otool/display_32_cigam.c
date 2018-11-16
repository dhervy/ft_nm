/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_32_cigam.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:20:47 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:20:48 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void	affi_otool_addr_32_cigam(t_all *all, char *ptr, struct section *section)
{
	char	*res;
	int		i;

	res = NULL;
	i = -1;
	res = llx(swap32(section->addr) +\
		(ptr - (all->ptr + swap32(section->offset) + all->off)));
	while ((ft_strlen(res) + ++i) < 8)
		ft_putchar('0');
	ft_putstr(res);
	free(res);
	ft_putstr("\t");
}

void	affi_otool_norm_32_cigam(char *ptr)
{
	char			*tmp;
	char			*res;

	res = NULL;
	tmp = NULL;
	if (*(ptr) < 0)
	{
		tmp = llx(swap32(*(ptr)));
		res = ft_strndup(tmp, 2);
		free(tmp);
	}
	else
		res = llx(*(ptr));
	if (ft_strlen(res) == 1)
		ft_putchar('0');
	ft_putstr(res);
	free(res);
}

char	*affi_otool_ptr_32_cigam(t_all *all, struct section *section)
{
	if (all->bonus_d)
		ft_putendl("Contents of (__DATA,__data) section");
	else
		ft_putendl("Contents of (__TEXT,__text) section");
	return ((char*)(all->ptr) + swap32(section->offset) + all->off);
}

void	affi_otool_32_cigam(t_all *all, struct section *section)
{
	char			*ptr;
	uint64_t		i;
	int				pad;

	i = -1;
	pad = 0;
	ptr = affi_otool_ptr_32_cigam(all, section);
	while (++i < swap32(section->size))
	{
		if ((pad = (pad == 16 ? 0 : pad)) == 0)
			affi_otool_addr_32_cigam(all, ptr, section);
		affi_otool_norm_32_cigam(ptr);
		ptr++;
		affi_otool_pad(all, &pad);
	}
	affi_otool_nb(pad);
}
