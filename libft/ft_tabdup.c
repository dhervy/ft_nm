/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 18:12:51 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/25 18:30:57 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab, int size)
{
	char	**new;
	int		i;

	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < size - 1)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new);
}
