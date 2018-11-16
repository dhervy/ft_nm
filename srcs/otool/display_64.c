/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:20:51 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:20:52 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void	affi_otool_addr_64(t_all *all, char *ptr, struct section_64 *section_64)
{
	char	*res;
	int		i;

	res = NULL;
	i = -1;
	res = llx(section_64->addr +\
		(ptr - (all->ptr + section_64->offset + all->off)));
	while ((ft_strlen(res) + ++i) < 16)
		ft_putchar('0');
	ft_putstr(res);
	free(res);
	ft_putstr("\t");
}

void	affi_otool_norm_64(char *ptr)
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

char	*affi_otool_ptr_64(t_all *all, struct section_64 *section_64)
{
	if (all->bonus_d)
		ft_putendl("Contents of (__DATA,__data) section");
	else
		ft_putendl("Contents of (__TEXT,__text) section");
	return ((char*)(all->ptr) + section_64->offset + all->off);
}

void	affi_otool_64(t_all *all, struct section_64 *section_64)
{
	char			*ptr;
	uint64_t		i;
	int				pad;

	i = -1;
	pad = 0;
	ptr = affi_otool_ptr_64(all, section_64);
	while (++i < section_64->size)
	{
		if ((pad = (pad == 16 ? 0 : pad)) == 0)
			affi_otool_addr_64(all, ptr, section_64);
		affi_otool_norm_64(ptr);
		ptr++;
		affi_otool_pad(all, &pad);
	}
	affi_otool_nb(pad);
}
