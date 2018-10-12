/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:58:33 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/07 21:40:13 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char *s2;

	if (!(s2 = (char*)malloc(sizeof(*s2) * len + 1)))
		return (NULL);
	ft_strncpy(s2, s1, len);
	s2[len] = '\0';
	return (s2);
}
