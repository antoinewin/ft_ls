/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:17:02 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 11:17:15 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_time(time_t date)
{
	char	*str;
	char	**tab;

	str = ctime(&date);
	tab = ft_strsplit(str, ' ');
	ft_putstr(tab[1]);
	ft_putchar(' ');
	if (ft_strlen(tab[2]) < 2)
		ft_putchar(' ');
	ft_putstr(tab[2]);
	ft_putchar(' ');
	if ((time(0) - date) > 15778463 || ((time(0) - date) < 0))
		ft_putchar(' ');
	if ((time(0) - date) > 15778463 || ((time(0) - date) < 0))
		ft_putnstr(tab[4], 4);
	else
		ft_putnstr(tab[3], 5);
	ft_strdel(tab);
	ft_putchar(' ');
}

void	ft_print_total(t_size *size, t_opt *opt)
{
	if (opt->l)
	{
		ft_putstr("total ");
		ft_putnbr(size->total);
		ft_putchar('\n');
	}
}

void	ft_print_enoent(char *name)
{
	ft_putstr("ft_ls: ");
	ft_errors(name, "No such file or directory", 0);
}

void	ft_print_eacces(char *path)
{
	ft_putchar('\n');
	ft_putstr(path);
	ft_putendl(":");
	ft_putstr("ft_ls: ");
	ft_errors(ft_istrchr(path), "Permission denied", 0);
}
