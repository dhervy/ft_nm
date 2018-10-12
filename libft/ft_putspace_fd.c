/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 23:52:29 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/15 20:05:06 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putspace_fd(int size, int fd)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
}
