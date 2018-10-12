/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 18:34:04 by dhervy            #+#    #+#             */
/*   Updated: 2016/04/29 21:12:18 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishexa(char *str)
{
	int i;

	i = 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
	{
		i = 2;
		while (str[i] != '\0')
		{
			if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70)
				|| (str[i] >= 97 && str[i] <= 102))
				i++;
			else
				return (0);
		}
		return (1);
	}
	else
		return (0);
}

int		ft_puissance(int nbr, int puissance)
{
	int result;

	result = 1;
	if (puissance == 0)
		return (1);
	while (puissance-- > 0)
	{
		result = result * nbr;
	}
	return (result);
}

int		ft_recupint(char c)
{
	if (ft_isdigit(c))
	{
		return (c - 48);
	}
	else if (ft_isalpha(c))
	{
		if (c >= 65 && c <= 70)
			return ((c - 65) + 10);
		else if (c >= 97 && c <= 102)
			return ((c - 97) + 10);
	}
	return (0);
}

int		ft_hexatoint(char *str)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	if (ft_ishexa(str) == 0)
		return (0);
	str = &str[2];
	i = ft_strlen(str);
	while (i > 0)
	{
		result = result + (ft_recupint(str[j]) * ft_puissance(16, i - 1));
		i--;
		j++;
	}
	return (result);
}
