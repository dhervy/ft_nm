/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:19:27 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:19:41 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void	nm_norm(t_all *all)
{
	if (all->magic_number == FAT_MAGIC)
	{
		ft_putendl("Fichier FAT 32");
	}
	else if (all->magic_number == FAT_CIGAM)
	{
		handle_fat_32(all);
	}
	else
	{
		ft_putstr_fd(all->name, 2);
		ft_putendl_fd(" The file was not recognized as a valid object file", 2);
		ft_putchar_fd('\n', 2);
	}
}

void	nm(t_all *all)
{
	all->magic_number = *(int *)all->ptr;
	if (all->magic_number == MH_MAGIC_64)
	{
		display_name(all);
		handle_64(all);
	}
	else if (all->magic_number == MH_CIGAM_64)
	{
		ft_putendl("Fichier 64 bit cigam");
	}
	else if (all->magic_number == MH_MAGIC)
	{
		display_name(all);
		handle_32(all);
	}
	else if (all->magic_number == MH_CIGAM)
	{
		display_name(all);
		handle_32_cigam(all);
	}
	else
		nm_norm(all);
}
