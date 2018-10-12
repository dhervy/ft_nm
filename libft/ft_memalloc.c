/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:05:26 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/18 19:16:10 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	if (!size)
		return (NULL);
	if (!(new = (void*)malloc(sizeof(void*) * size + 1)))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
