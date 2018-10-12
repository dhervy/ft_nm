/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:52:47 by dhervy            #+#    #+#             */
/*   Updated: 2016/11/21 18:52:49 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabndup(char **tab, int size, int n)
{
	char	**new;
	int		i;

	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * size);
	while (i < n)
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new);
}
