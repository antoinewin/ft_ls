/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:21:04 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/05 14:09:19 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt	*ft_create_opt(void)
{
	t_opt	*opt;

	opt = NULL;
	if ((opt = (t_opt*)ft_memalloc(sizeof(t_opt))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	opt->l = 0;
	opt->re = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->off = 1;
	return (opt);
}

t_elem	*ft_create_elem(void)
{
	t_elem	*list;

	list = NULL;
	if ((list = (t_elem*)ft_memalloc(sizeof(t_elem))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	list->prv = NULL;
	list->nxt = NULL;
	list->name = NULL;
	list->path = NULL;
	list->date = 0;
	return (list);
}
