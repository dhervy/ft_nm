/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:20:00 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:20:02 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

char		*all_type(char *segname, char *sectname, uint8_t n_type)
{
	if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__bss"))
		return (ft_strdup(n_type & N_EXT ? "B" : "b"));
	else if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__data"))
		return (ft_strdup(n_type & N_EXT ? "D" : "d"));
	else if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__text"))
		return (ft_strdup(n_type & N_EXT ? "T" : "t"));
	else
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
}
