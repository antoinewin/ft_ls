/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 14:48:23 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 12:30:23 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print(t_size *size, t_elem *list, t_opt *opt)
{
	if (opt->l)
	{
		ft_print_permi(list->st_mode, list->sub);
		ft_print_int(list->st_nlink, size->linksize);
		ft_print_gn(list->username, size->usersize);
		ft_print_gn(list->groupname, size->groupsize);
		if (list->sub == DT_CHR || list->sub == DT_BLK)
			ft_print_majmin(list, size);
		else
			ft_print_int(list->st_size, size->size);
		ft_print_time(list->date);
	}
	ft_putstr(list->name);
	if (opt->l)
		ft_print_lnk(list);
	ft_putchar('\n');
}

void	ft_print_file(t_error *errors, t_opt *opt)
{
	while (errors->prv)
		errors = errors->prv;
	while (errors->erno == 2)
	{
		ft_print_enoent(errors->name);
		if (errors->nxt == NULL)
			break ;
		errors = errors->nxt;
	}
	while (errors->erno == 10)
	{
		if (opt->l)
		{
			ft_putstr("-------");
			ft_putendl(errors->name);
		}
		else
			ft_putendl(errors->name);
		errors = errors->nxt;
	}
	while (errors->erno == 13)
	{
		ft_print_eacces(errors->name);
		if (errors->nxt == NULL)
			break ;
		errors = errors->nxt;
	}
}

void	ls_r_on(t_elem *list, t_opt *opt)
{
	t_size	*size;

	while (list->nxt)
		list = list->nxt;
	size = ft_calcsize(list, opt);
	ft_print_total(size, opt);
	while (list)
	{
		if (list->name[0] != '.' || (opt->a))
			ft_print(size, list, opt);
		list = list->prv;
	}
}

void	ls_r_off(t_elem *list, t_opt *opt)
{
	t_size	*size;

	while (list->prv)
		list = list->prv;
	size = ft_calcsize(list, opt);
	ft_print_total(size, opt);
	while (list)
	{
		if (list->name[0] != '.' || (opt->a))
			ft_print(size, list, opt);
		list = list->nxt;
	}
}
