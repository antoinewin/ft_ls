/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:47:42 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/03 16:19:12 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			ft_putchar_fd(s[i], fd);
		ft_putchar_fd('\n', fd);
	}
}
