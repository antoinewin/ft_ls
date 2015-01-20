/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 14:06:35 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 12:33:19 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_dir_r(t_error *dir, t_opt *opt, int aci)
{
	while (dir->nxt)
		dir = dir->nxt;
	while (dir)
	{
		if (aci > 1)
			ft_putchar('\n');
		ls_dir_list(dir->name, opt, aci, ft_istrchr(dir->name));
		dir = dir->prv;
	}
}

int		ft_maybedir(t_elem *list)
{
	if (S_ISLNK(list->st_mode))
		return (DT_LNK);
	if (S_ISREG(list->st_mode))
		return (DT_REG);
	if (S_ISCHR(list->st_mode))
		return (DT_CHR);
	if (S_ISBLK(list->st_mode))
		return (DT_BLK);
	if (S_ISFIFO(list->st_mode))
		return (DT_FIFO);
	if (S_ISSOCK(list->st_mode))
		return (DT_SOCK);
	if (S_ISDIR(list->st_mode))
		return (DT_DIR);
	else
		return (DT_UNKNOWN);
}

void	ft_isDir(t_elem *elem, struct dirent *dir)
{
	DIR		*directory;

	if (elem)
	{
		if (dir && dir->d_type == DT_LNK)
			elem->sub = DT_LNK;
		else if (dir && dir->d_type == DT_DIR)
			elem->sub = DT_DIR;
		else if (dir && dir->d_type == DT_CHR)
			elem->sub = DT_CHR;
		else if (dir && dir->d_type == DT_BLK)
			elem->sub = DT_BLK;
		else if (dir && dir->d_type == DT_SOCK)
			elem->sub = DT_SOCK;
		else
		{
			if ((elem->sub = ft_maybedir(elem)) != DT_UNKNOWN)
				return ;
			else if ((directory = opendir(elem->path)))
			{
				elem->sub = DT_DIR;
				closedir(directory);
			}
		}
	}
}

int		ft_getuid(t_elem *elem, uid_t st_uid, gid_t st_gid)
{
	struct passwd	*passwd;
	struct group	*group;

	passwd = getpwuid(st_uid);
	if (passwd == NULL)
		return (0);
	if ((elem->username = (char *)ft_memalloc(ft_strlen(passwd->pw_name))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	elem->username = ft_strcpy(elem->username, passwd->pw_name);
	group = getgrgid(st_gid);
	if (group == NULL)
		return (0);
	if ((elem->groupname = (char *)ft_memalloc(ft_strlen(group->gr_name))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	elem->groupname = ft_strcpy(elem->groupname, group->gr_name);
	return (1);
}

void	ls_add_elem(char *path, t_elem *elem, struct stat *buf, struct dirent *entry)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	elem->path = ft_strjoin(tmp, elem->name);
	free(tmp);
	if (lstat(elem->path, buf) == -1)
	{
		ft_error("ft_ls", elem->name, 0);
		elem->sub = -1;
	}
	elem->st_mode = buf->st_mode;
	ft_isDir(elem, entry);
	elem->st_mode = buf->st_mode;
	elem->st_nlink = buf->st_nlink;
	elem->st_blocks = buf->st_blocks;
	elem->st_rdev = buf->st_rdev;
	elem->date = buf->st_mtime;
	ft_getuid(elem, buf->st_uid, buf->st_gid);
	elem->st_size = buf->st_size;
}

char	*ft_istrchr(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] == '/')
			return (&str[i + 1]);
		i--;
	}
	return (str);
}
