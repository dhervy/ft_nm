/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:18:07 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:18:09 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

int			find_my_arch(t_all *all)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					nbheader;
	void				*arch_ptr;
	int					i;

	i = -1;
	header = (struct fat_header *)all->ptr;
	nbheader = swap32(header->nfat_arch);
	arch_ptr = (void*)header + sizeof(struct fat_header);
	while (++i < nbheader)
	{
		arch = (struct fat_arch *)arch_ptr;
		all->off = swap32(arch->offset);
		all->magic_number = *(uint32_t*)((uintptr_t)all->ptr + all->off);
		if ((unsigned int)(all->magic_number) == MH_MAGIC_64)
			return (find_my_arch_norm(all));
		arch_ptr += sizeof(struct fat_arch);
	}
	return (0);
}

void		handle_fat_32_write(t_all *all, struct fat_arch *arch)
{
	if (!all->bonus_a)
	{
		ft_putstr("\n");
		ft_putstr(all->name);
		ft_putstr(" (for ");
		ft_putstr("architecture ");
		ft_putstr(find_cputype(all, swap32(arch->cputype)));
	}
	all->off = swap32(arch->offset);
	all->magic_number = *(uint32_t*)((uintptr_t)all->ptr + all->off);
}

int			handle_fat_32_init(t_all *all, struct fat_header **header,\
	int *nbheader)
{
	*header = (struct fat_header *)all->ptr;
	*nbheader = swap32((*header)->nfat_arch);
	if (find_my_arch(all) == 1)
		return (1);
	return (0);
}

void		handle_fat_32_norm(t_all *all)
{
	if ((unsigned int)(all->magic_number) == MH_MAGIC)
		handle_32(all);
	else if ((unsigned int)(all->magic_number) == MH_CIGAM)
		handle_32_cigam(all);
	else if ((unsigned int)(all->magic_number) == MH_MAGIC_64)
		handle_64(all);
	else
		ft_putendl("MH not found");
}

void		handle_fat_32(t_all *all)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					nbheader;
	void				*arch_ptr;
	int					i;

	all->cpu = 32;
	if (handle_fat_32_init(all, &header, &nbheader) == 1)
		return ;
	i = -1;
	arch_ptr = (void*)header + sizeof(struct fat_header);
	while (++i < nbheader)
	{
		arch = (struct fat_arch *)arch_ptr;
		if (nbheader > 1)
			handle_fat_32_write(all, arch);
		else
		{
			ft_putstr(all->name);
			ft_putendl(":");
		}
		handle_fat_32_norm(all);
		all->arch_ppc = 0;
		arch_ptr += sizeof(struct fat_arch);
	}
}
