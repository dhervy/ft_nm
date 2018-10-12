/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:35:52 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/18 18:47:44 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	ft_strcpy(str, &s[i]);
	i = ft_strlen(str);
	while (ft_isspace(str[i - 1]))
	{
		str[i - 1] = '\0';
		i--;
	}
	if (!(new = ft_strnew(ft_strlen(str))))
		return (NULL);
	ft_strncpy(new, str, i);
	free(str);
	return (new);
}
