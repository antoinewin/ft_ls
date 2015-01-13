/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 14:49:31 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/13 10:46:33 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_majmin(t_elem *list, t_size *size)
{
	int min;
	int maj;

	if (list->sub == DT_CHR || list->sub == DT_BLK)
	{
		min = ft_countnum(LS_MINOR(list->st_rdev));
		maj = ft_countnum(LS_MAJOR(list->st_rdev));
		while (maj++ < size->maj)
			ft_putchar(' ');
		ft_putnbr(LS_MAJOR(list->st_rdev));
		ft_putstr(",");
		while (min++ < size->min)
			ft_putchar(' ');
		ft_putnbr(LS_MINOR(list->st_rdev));
		ft_putchar(' ');
	}
}

void	ft_calcmm(t_elem *list, t_size *size)
{
	int	i;

	i = 0;
	while (list)
	{
		if (list->sub == DT_CHR || list->sub == DT_BLK)
		{
			i = ft_countnum(LS_MINOR(list->st_rdev));
			if (i > size->min)
				size->min = i;
			i = ft_countnum(LS_MAJOR(list->st_rdev));
			if (i > size->maj)
				size->maj = i;
			i = size->min + size->maj + 1;
			if (i > size->size)
				size->size = i;
		}
		list = list->nxt;
	}
}

int		ft_usersize(t_elem *list, t_opt *opt)
{
	int	usersize;
	int	i;

	usersize = 0;
	while (list)
	{
		if (list->name[0] != '.' || (opt->a))
		{
			i = ft_strlen(list->username);
			if (usersize < i)
				usersize = i;
		}
		list = list->nxt;
	}
	return (usersize);
}

int		ft_groupsize(t_elem *list, t_opt *opt)
{
	int	groupsize;
	int	i;

	groupsize = 0;
	while (list)
	{
		if (list->name[0] != '.' || (opt->a))
		{
			i = ft_strlen(list->groupname);
			if (groupsize < i)
				groupsize = i;
		}
		list = list->nxt;
	}
	return (groupsize);
}

int		ft_linksize(t_elem *list, t_opt *opt)
{
	int	maxsize;
	int	i;

	maxsize = 0;
	while (list)
	{
		if (list->name[0] != '.' || (opt->a))
		{
			i = ft_countnum(list->st_nlink);
			if (maxsize < i)
				maxsize = i;
		}
		list = list->nxt;
	}
	return (maxsize);
}

t_elem	*ft_maxsize(t_elem *list, t_size *size, t_opt *opt)
{
	int		maxsize;
	int		i;
	t_elem	*first;

	maxsize = 0;
	while (list->prv)
		list = list->prv;
	first = list;
	while (list)
	{
		if (list->name[0] != '.' || (opt->a))
		{
			size->total = list->st_blocks + size->total;
			i = ft_countnum(list->st_size);
			if (maxsize < i)
				maxsize = i;
		}
		list = list->nxt;
	}
	size->size = maxsize;
	return (first);
}

t_size	*ft_calcsize(t_elem *list, t_opt *opt)
{
	t_size	*size;

	size = NULL;
	if (list && opt->l)
	{
		size = ft_create_size();
		list = ft_maxsize(list, size, opt);
		size->groupsize = ft_groupsize(list, opt);
		size->usersize = ft_usersize(list, opt);
		size->linksize = ft_linksize(list, opt);
		ft_calcmm(list, size);
	}
	return (size);
}
