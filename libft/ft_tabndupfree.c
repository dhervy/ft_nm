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

char	**ft_tabndupfree(char **tab, int size, int n)
{
	char	**new;
	int		i;

	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < n)
	{
		new[i] = ft_strdupfree(tab[i]);
		i++;
	}
	free(tab);
	return (new);
}
