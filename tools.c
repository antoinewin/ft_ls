/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 14:06:35 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/08 13:33:04 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_cut_ctime(char *time)
{
	int		off;

	off = 1;
	while (*time)
	{
		if (*time == ' ')
		{
			time++;
			break ;
		}
		time++;
	}
	while (*time)
	{
		if (*time == ':' && off)
			off = 0;
		else if (*time == ':')
			break ;
		ft_putchar(*time);
		time++;
	}
}

void	ft_isDir(t_elem *elem)
{
	DIR		*dir;

	errno = 0;
	if (elem)
	{
		if ((dir = opendir(elem->path)) == NULL)
		{
			if (errno == ENOTDIR)
				elem->sub = 0;
			else
				elem->sub = 1;
		}
		else if (S_ISLNK(elem->st_mode))
			elem->sub = 0;
		else
		{
			elem->sub = 1;
			closedir(dir);
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

void	ls_add_elem(char *path, t_elem *elem, struct stat *buf)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	elem->path = ft_strjoin(tmp, elem->name);
	free(tmp);
	stat(elem->path, buf);
	elem->st_mode = buf->st_mode;
	ft_isDir(elem);
	if (elem->sub == 1)
	{
		lstat(elem->path, buf);
		elem->st_mode = buf->st_mode;
		if (S_ISLNK(elem->st_mode))
			elem->sub = 0;
	}
	elem->st_nlink = buf->st_nlink;
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
