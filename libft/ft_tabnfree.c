/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 21:20:07 by dhervy            #+#    #+#             */
/*   Updated: 2017/04/03 21:20:10 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabnfree(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_bzero(tab[i], ft_strlen(tab[i]));
		free(tab[i]);
		i++;
	}
	free(tab);
}
