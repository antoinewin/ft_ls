/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_elem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 12:33:01 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/13 11:33:31 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_elem_before(t_elem *list1, t_elem *list2)
{
	list1->nxt = list2;
	list2->prv = list1;
}

void	ls_elem_between(t_elem *list, t_elem *list1, t_elem *list2)
{
	list1->nxt = list;
	list->prv = list1;
	list->nxt = list2;
	list2->prv = list;
}

t_elem	*ls_place_elem_name(t_elem *elem, t_elem *list, t_opt *opt)
{
	if (opt->t)
		while (ft_strcmp(elem->name, list->name) > 0 && elem->date == list->date
				&& list->nxt != NULL)
			list = list->nxt;
	else
		while (ft_strcmp(elem->name, list->name) > 0 && list->nxt != NULL)
			list = list->nxt;
	if (list->prv == NULL && ft_strcmp(elem->name, list->name) <= 0)
		ls_elem_before(elem, list);
	else if (list->nxt == NULL && ft_strcmp(elem->name, list->name) >= 0)
		ls_elem_before(list, elem);
	else
		ls_elem_between(elem, list->prv, list);
	return (elem);
}

t_elem	*ls_place_elem(t_elem *elem, t_elem *list, t_opt *opt)
{
	if (!list)
		return (elem);
	while (list->prv)
		list = list->prv;
	if (opt->t)
	{
		while (elem->date < list->date && list->nxt != NULL)
			list = list->nxt;
		if (list->prv == NULL && elem->date > list->date)
			ls_elem_before(elem, list);
		else if (list->nxt == NULL && elem->date < list->date)
			ls_elem_before(list, elem);
		else if (elem->date == list->date)
			ls_place_elem_name(elem, list, opt);
		else
			ls_elem_between(elem, list->prv, list);
	}
	else
		ls_place_elem_name(elem, list, opt);
	return (elem);
}
