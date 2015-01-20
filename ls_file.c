/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:27:35 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 09:32:27 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

DIR		*ls_open_file(char *name, char *path)
{
	DIR		*dir;

	if ((dir = opendir(path)) == NULL)
	{
		if (errno == ENOTDIR)
		{
			ft_putendl(name);
			return (NULL);
		}
		ft_error("ft_ls", name, 0);
		return (NULL);
	}
	return (dir);
}
