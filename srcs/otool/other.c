/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:38:45 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 19:42:28 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void	print_name(t_all *all)
{
	ft_putstr(all->name);
	ft_putendl(":");
}

int		handle_fat_32_init(t_all *all, struct fat_header **header,\
		int *nbheader)
{
	*header = (struct fat_header *)all->ptr;
	*nbheader = swap32((*header)->nfat_arch);
	if (find_my_arch(all) == 1)
		return (1);
	return (0);
}
