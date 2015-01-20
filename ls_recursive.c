/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:37:05 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 09:45:52 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*ft_free_on(t_elem *list)
{
	t_elem	*tmp;

	tmp = NULL;
	if (list)
	{
		if (list->prv)
			tmp = list->prv;
		else
			tmp = NULL;
		list->prv = NULL;
		list->nxt = NULL;
		free(list->name);
		free(list->path);
		list->sub = 0;
		list->date = 0;
		free(list);
	}
	return (tmp);
}

t_elem	*ft_free_off(t_elem *list)
{
	t_elem	*tmp;

	tmp = NULL;
	if (list)
	{
		if (list->nxt)
			tmp = list->nxt;
		else
			tmp = NULL;
		list->prv = NULL;
		list->nxt = NULL;
		free(list->name);
		free(list->path);
		list->sub = 0;
		list->date = 0;
		free(list);
	}
	return (tmp);
}

t_elem	*ls_recursive_r_on(t_elem *list, t_opt *opt)
{
	while (list->nxt)
		list = list->nxt;
	while (list && list->prv)
	{	
		if ((list->sub == DT_DIR) && ft_strcmp(list->name, "..") != 0
				&& ft_strcmp(list->name, ".") != 0 && list)
		{
			if (list->name[0] != '.' || (opt->a))
				ft_putchar('\n');
			ls_dir_list(list->path, opt, 3, list->name);
		}
		list = ft_free_on(list);
	}
	return (list);
}

t_elem	*ls_recursive_r_off(t_elem *list, t_opt *opt)
{
	while (list->prv)
		list = list->prv;
	while (list && list->nxt)
	{
		if ((list->sub == DT_DIR) && ft_strcmp(list->name, "..") != 0
				&& ft_strcmp(list->name, ".") != 0 && list)
		{
			if (list->name[0] != '.' || (opt->a))
				ft_putchar('\n');
			ls_dir_list(list->path, opt, 3, list->name);
		}
		list = ft_free_off(list);
	}
	return (list);
}

void	ls_recursive(t_elem *list, t_opt *opt)
{
	if (opt->r)
		list = ls_recursive_r_on(list, opt);
	else
		list = ls_recursive_r_off(list, opt);
	if ((list->sub == DT_DIR) && ft_strcmp(list->name, "..") != 0
			&& ft_strcmp(list->name, ".") != 0 && list)
	{
		if (list->name[0] != '.' || (opt->a))
			ft_putchar('\n');
		ls_dir_list(list->path, opt, 3, list->name);
	}
}
