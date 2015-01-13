/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:28:07 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/13 12:03:53 by achauvea         ###   ########.fr       */
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

int		*ls_param(int ac, int i, char **av, t_opt *opt)
{
	DIR		*dir;
	int		*file;
	int		*par;
	int		x[1];

	x[0] = 0;
	x[1] = 0;
	if ((par = (int*)ft_memalloc(ac - i)) == NULL
			|| (file = (int*)ft_memalloc(ac - i)) == NULL)
		ft_error("ft_ls", "malloc", 1);
	while (ac > i)
	{
		if ((dir = opendir(av[i])) == NULL)
		{
			if (errno == ENOTDIR)
				file[x[1]++] = i;
		}
		else
			par[x[0]++] = i;
		if (dir && (closedir(dir)) == -1)
			ft_error("ft_ls", av[i], 1);
		i++;
	}
	ft_print_file(file, av, opt);
	free(file);
	return (par);
}

int		main(int ac, char **av)
{
	int		i;
	int		y;
	int		*par;
	t_opt	*opt;

	opt = ft_create_opt();
	i = ls_arguments(ac, av, opt);
	if (i > 0)
	{
		par = ls_param(ac, i, av, opt);
		y = -1;
		while (par[++y])
		{
			if ((ac - i) > 1)
				ft_putchar('\n');
			ls_dir_list(av[par[y]], opt, (ac - i), ft_istrchr(av[par[y]]));
		}
	}
	else
		ls_dir_list(".", opt, 0, ".");
	return (0);
}
