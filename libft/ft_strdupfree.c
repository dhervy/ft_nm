/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:56:50 by dhervy            #+#    #+#             */
/*   Updated: 2016/02/09 20:57:14 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupfree(const char *s1)
{
	char *s2;

	if (!(s2 = (char*)malloc(sizeof(*s2) * ft_strlen(s1) + 1)))
		return (NULL);
	ft_strcpy(s2, s1);
	free((char*)s1);
	return (s2);
}
