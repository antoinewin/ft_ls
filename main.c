/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:28:07 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 12:37:28 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_print_list(t_elem *list, t_opt *opt, char *name)
{
	if (list && name && (name[0] != '.' || (opt->a) || (opt->off)))
	{
		if (opt->r)
			ls_r_on(list, opt);
		else
			ls_r_off(list, opt);
	}
	opt->off = 0;
}

t_elem	*ls_on_list(struct dirent *entry, t_opt *opt, t_elem *list, char *path)
{
	t_elem		*elem;
	struct stat	*buf;

	elem = ft_create_elem();
	if ((elem->name = (char*)ft_memalloc(ft_strlen(entry->d_name))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	if ((buf = (struct stat*)ft_memalloc(sizeof(struct stat))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	elem->name = ft_strcpy(elem->name, entry->d_name);
	ls_add_elem(path, elem, buf, entry);
	list = ls_place_elem(elem, list, opt);
	free(buf);
	return (list);
}

int		ls_dir_list(char *path, t_opt *opt, int ac, char *name)
{
	DIR				*dir;
	struct dirent	*entry;
	t_elem			*list;

	list = NULL;
	if (ac > 1 && (name) && (name[0] != '.' || (opt->a)))
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	if ((dir = ls_open_file(name, path)) == NULL)
		return (0);
	while ((entry = readdir(dir)))
		list = ls_on_list(entry, opt, list, path);
	if ((closedir(dir)) == -1 || list == NULL)
	{
		ft_error("ft_ls", name, 0);
		return (0);
	}
	ls_print_list(list, opt, name);
	if (opt->re)
		ls_recursive(list, opt);
	return (0);
}

t_error	*ls_param(int ac, int i, char **av, t_opt *opt)
{
	DIR		*dir;
	t_error	*doss;
	t_error	*errors;

	errors = ft_create_error();
	doss = ft_create_error();
	while (ac > i)
	{
		if ((dir = opendir(av[i])) == NULL)
		{
			if (errno == ENOTDIR)
				ft_putendl("Fileattente");
			else if (errno == EACCES || errno == ENOENT)
				errors = ls_error(errors, av[i], 1);
			else
				ft_error("ft_ls", av[i], 0);
		}
		else
			doss = ls_error(doss, av[i], 0);
		if (dir && (closedir(dir)) == -1)
			ft_error("ft_ls", av[i], 1);
		i++;
	}
	ft_print_file(errors, opt);
	free(errors);
	return (doss);
}

int		main(int ac, char **av)
{
	int		i;
	t_opt	*opt;
	t_error	*dir;

	opt = ft_create_opt();
	dir = ft_create_error();
	i = ls_arguments(ac, av, opt);
	if (i > 0)
	{
		dir = ls_param(ac, i, av, opt);
		if (opt->r)
		{
			ls_dir_r(dir, opt, (ac - i));
			return (0);
		}
		while (dir->prv)
			dir = dir->prv;
		while (dir)
		{
			if ((ac - i) > 1)
				ft_putchar('\n');
			ls_dir_list(dir->name, opt, (ac - i), ft_istrchr(dir->name));
			dir = dir->nxt;
		}
	}
	else
		ls_dir_list(".", opt, 0, ".");
	return (0);
}
