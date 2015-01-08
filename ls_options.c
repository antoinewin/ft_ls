/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 21:02:26 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/27 15:32:57 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_error_options(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ft_ls [-Ralrt] [file ...]");
	exit(0);
}

static void	ls_options(char *str, t_opt *opt)
{
	++str;
	while (*str)
	{
		if (*str == 'l')
			opt->l = 1;
		else if (*str == 'R')
			opt->re = 1;
		else if (*str == 'a')
			opt->a = 1;
		else if (*str == 'r')
			opt->r = 1;
		else if (*str == 't')
			opt->t = 1;
		else
			ft_error_options(*str);
		++str;
	}
}

int			ls_arguments(int ac, char **av, t_opt *opt)
{
	int		i;

	i = 0;
	while (ac > ++i)
	{
		if (av[i][0] == '-' && (av[i][1]) &&
				(av[i][1] != '-' || (av[i][2])))
			ls_options(av[i], opt);
		else
			return (i);
	}
	return (0);
}
