/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:31:57 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/10 18:17:38 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_nbr(int n, char *str)
{
	if (n >= 10)
	{
		ft_nbr(n / 10, str);
		ft_nbr(n % 10, str);
	}
	else
		ft_charcat(str, n + 48);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	char	*new;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(12)))
		return (NULL);
	if (n < 0)
	{
		ft_strcpy(str, "-");
		n = n * -1;
	}
	ft_nbr(n, str);
	new = ft_strdup(str);
	free(str);
	return (new);
}
