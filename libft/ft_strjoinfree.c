/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:44:54 by dhervy            #+#    #+#             */
/*   Updated: 2016/02/09 20:49:39 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int i)
{
	char *new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = ft_strnew((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	if (i == 0)
		free((char*)s1);
	else if (i == 1)
		free((char*)s2);
	else if (i == 2)
	{
		free((char*)s1);
		free((char*)s2);
	}
	return (new);
}
