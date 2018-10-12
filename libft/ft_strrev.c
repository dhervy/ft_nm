/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:58:26 by dhervy            #+#    #+#             */
/*   Updated: 2016/01/12 12:41:08 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	int		k;
	char	tmp;

	j = 0;
	i = ft_strlen(str) - 1;
	k = (i + 1) / 2;
	while (i >= k)
	{
		tmp = str[j];
		str[j++] = str[i];
		str[i--] = tmp;
	}
	return (str);
}
