/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 13:12:04 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/08 14:45:34 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_type(int sub)
{
	if (sub == DT_DIR)
		ft_putchar('d');
	else if (sub == DT_LNK)
		ft_putchar('l');
	else if (sub == DT_BLK)
		ft_putchar('b');
	else if (sub == DT_CHR)
		ft_putchar('c');
	else if (sub == DT_SOCK)
		ft_putchar('s');
	else if (sub == DT_FIFO)
		ft_putchar('p');
	else if (sub == DT_REG)
		ft_putchar('-');
	else
		ft_putchar('?');
}

void	ft_print_permi(mode_t st_mode, int sub)
{
	ft_print_type(sub);
	ft_putchar(st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(st_mode & S_IWUSR ? 'w' : '-');
	if (st_mode & S_ISUID)
		ft_putchar(st_mode & S_IXUSR ? 's' : 'S');
	else
		ft_putchar(st_mode & S_IXUSR ? 'x' : '-');
	ft_putchar(st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(st_mode & S_IWGRP ? 'w' : '-');
	if (st_mode & S_ISGID)
		ft_putchar(st_mode & S_IXGRP ? 's' : 'S');
	else
		ft_putchar(st_mode & S_IXGRP ? 'x' : '-');
	ft_putchar(st_mode & S_IROTH ? 'r' : '-');
	ft_putchar(st_mode & S_IWOTH ? 'w' : '-');
	if (st_mode & S_ISVTX)
		ft_putchar(st_mode & S_IXOTH ? 't' : 'T');
	else
		ft_putchar(st_mode & S_IXOTH ? 'x' : '-');
	ft_putstr("  ");
}

void	ft_print_int(int size, unsigned int toprint)
{
	int		n;

	n = size - ft_countnum(toprint);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr(toprint);
	ft_putchar(' ');
}

void	ft_print_gn(char *name, int size)
{
	int n;

	n = size - ft_strlen(name);
	ft_putstr(name);
	while (n-- > 0)
		ft_putchar(' ');
	ft_putstr("  ");
}

void	ft_print_lnk(t_elem *list)
{
	char	*lnkcontent;
	int		ret;
	int		size;

	if (list->sub == DT_LNK)
	{
		size = 1024;
		if ((lnkcontent = (char *)ft_memalloc(sizeof(char) * (size))) == NULL)
			ft_error("ft_ls", "malloc", 1);
		ret = readlink(list->path, lnkcontent, size);
		lnkcontent[ret] = '\0';
		ft_putstr(" -> ");
		ft_putstr(lnkcontent);
		ft_strsupr(lnkcontent, size);
	}
}
