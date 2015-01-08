/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:17:02 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/08 13:17:13 by achauvea         ###   ########.fr       */
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

void	ft_print_total(t_size *size, t_arg *arg)
{
	if (arg->l == 1)
	{
		ft_putstr("total ");
		ft_putnbr(size->total);
		ft_putchar('\n');
	}
}
