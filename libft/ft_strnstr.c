/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 22:10:08 by dhervy            #+#    #+#             */
/*   Updated: 2015/11/30 18:47:04 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t m;
	size_t m2;
	size_t a;

	m = 0;
	a = 0;
	if (s2[a] == '\0')
		return ((char*)s1);
	while (s1[m] != '\0' && m < n)
	{
		m2 = m;
		while (s1[m2] == s2[a] && m2 < n)
		{
			m2++;
			a++;
			if (s2[a] == '\0')
				return (char*)(&s1[m]);
		}
		m++;
		a = 0;
	}
	return (NULL);
}
