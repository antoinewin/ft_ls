/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:06:57 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/09 13:18:12 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*alstnext;

	if (*alst && alst)
	{
		while (*alst)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			alstnext = (*alst)->next;
			free(*alst);
			*alst = alstnext;
		}
		*alst = NULL;
	}
}
