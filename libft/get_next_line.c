/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:19:38 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/04 14:59:56 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		get_read(char **line, t_save *ret)
{
	ft_bzero(ret->mem, BUFF_SIZE + 1);
	if (ret->save)
		ret->read = ft_strjoin(ret->save, ret->read);
	if (ft_charlen(ret->read, '\n') != -1)
	{
		*line = ft_strsub(ret->read, 0, ft_charlen(ret->read, '\n'));
		ret->save = ft_strchr(ret->read, '\n');
		(ret->save)++;
		return (1);
	}
	else
	{
		if ((ret->save = (char*)malloc(ft_strlen(ret->read) + 1)) == NULL)
			return (-1);
		ret->save = ft_strcpy(ret->save, ret->read);
	}
	return (0);
}

int		get_save(char **line, t_save *ret)
{
	if (ft_charlen(ret->save, '\n') != -1)
	{
		*line = ft_strsub(ret->save, 0, ft_charlen(ret->save, '\n'));
		ret->save = ft_strchr(ret->save, '\n');
		(ret->save)++;
		return (1);
	}
	return (0);
}

int		get_final(char **line, t_save *ret)
{
	if (ret->save && ft_isprint((int)ret->save[0]))
	{
		*line = ret->save;
		ret->save = NULL;
		return (1);
	}
	return (0);
}

t_save	*get_struct(int fd, t_save *ret)
{
	t_save	*new;

	if (ret)
	{
		while (ret->prv)
			ret = ret->prv;
		while (ret->fd != fd && ret->nxt != NULL)
			ret = ret->nxt;
		if (ret->fd == fd)
			return (ret);
	}
	if ((new = (t_save*)malloc(sizeof(t_save))) == NULL)
		return (NULL);
	new->fd = fd;
	new->save = NULL;
	new->prv = 0;
	if (ret)
		new->prv = ret;
	if (ret)
		ret->nxt = new;
	return (new);
}

int		ft_gnl(int const fd, char **line)
{
	static t_save	*ret;

	if (line == NULL)
		return (-1);
	if ((ret = get_struct(fd, ret)) == NULL)
		return (-1);
	if (ret->save && ft_charlen(ret->save, '\n') != -1)
		if (get_save(line, ret))
			return (1);
	if ((ret->mem = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	while ((ret->iread = read(fd, ret->mem, BUFF_SIZE)) > 0)
	{
		ret->read = ft_strnew(BUFF_SIZE + 1);
		ret->read = ft_strcpy(ret->read, ret->mem);
		if (get_read(line, ret))
			return (1);
	}
	if (get_final(line, ret))
		return (1);
	if (ret->iread == 0)
		return (0);
	return (-1);
}
