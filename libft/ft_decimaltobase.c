/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltobase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:05:20 by dhervy            #+#    #+#             */
/*   Updated: 2016/02/23 21:31:12 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_decimaltobase2(int nbr, int base, int number, int result)
{
	char	*str;
	int		i;
	char	*retour;

	i = 0;
	str = ft_strnew(number * 2);
	while (nbr > base)
	{
		result = nbr % base;
		nbr = nbr / base;
		if (result > 9)
			str[i++] = (result - 9) + 64;
		else
			str[i++] = result + 48;
	}
	if (nbr > 9)
		str[i] = (nbr - 9) + 64;
	else
		str[i] = nbr + 48;
	retour = ft_strrev(str);
	free(str);
	return (retour);
}

char	*ft_decimaltobase(int nbr, int base)
{
	int result;
	int i;
	int number;

	number = ft_countint(nbr);
	i = 10;
	result = 0;
	if (base > 10)
		return (ft_decimaltobase2(nbr, base, number, result));
	if (base <= 1 || base > 36)
		return ("error");
	else
	{
		result = result + (nbr % base);
		nbr = nbr / base;
		while (nbr >= base)
		{
			result = result + (nbr % base * i);
			i = i * 10;
			nbr = nbr / base;
		}
		result = result + (nbr * i);
		return (ft_itoa(result));
	}
}
