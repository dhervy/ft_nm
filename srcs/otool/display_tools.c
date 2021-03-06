/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:20:54 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:20:55 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void		affi_otool_nb(int pad)
{
	if (pad != 16)
		ft_putchar('\n');
}

void		affi_otool_pad(t_all *all, int *pad)
{
	(*pad)++;
	if (!all->arch_ppc || !((*pad) % 4))
		ft_putchar(' ');
	if ((*pad) == 16)
		ft_putchar('\n');
}
