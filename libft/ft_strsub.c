/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:27:04 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/18 18:41:25 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	if (ft_strlen(s) >= start + len)
	{
		new = ft_strnew(len);
		if (new)
		{
			ft_strncpy(new, &s[start], len);
			return (new);
		}
	}
	return (NULL);
}
