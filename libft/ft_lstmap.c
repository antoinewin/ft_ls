/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:43:09 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/09 13:56:24 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if ((ret = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (lst && f)
	{
		while (lst)
		{
			ret = (*f)(lst);
			lst = (lst)->next;
		}
		return (ret);
	}
	return (NULL);
}
