/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:21:04 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 10:36:30 by achauvea         ###   ########.fr       */
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

t_error	*ft_create_error(void)
{
	t_error	*errors;

	errors = NULL;
	if ((errors = (t_error*)ft_memalloc(sizeof(t_error))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	errors->prv = NULL;
	errors->nxt = NULL;
	errors->name = NULL;
	errors->erno = 0;
	return (errors);
}

t_size	*ft_create_size(void)
{
	t_size	*size;

	size = NULL;
	if ((size = (t_size*)ft_memalloc(sizeof(t_size))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	size->total = 0;
	size->maj = 3;
	size->min = 4;
	return (size);
}
