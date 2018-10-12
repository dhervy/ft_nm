/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 19:52:57 by dhervy            #+#    #+#             */
/*   Updated: 2015/12/10 20:32:22 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *nxt;

	if (alst && del)
	{
		temp = *alst;
		while (temp != NULL)
		{
			nxt = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = nxt;
		}
		*alst = NULL;
	}
}
