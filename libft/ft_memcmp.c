/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:41:54 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:44:47 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ts1;
	char	*ts2;
	size_t	i;

	i = 0;
	ts1 = (char*)s1;
	ts2 = (char*)s2;
	if (ts1 && ts2)
	{
		while (i < n && ts1[i] == ts2[i])
			++i;
		if (i == n)
			return (0);
		return ((int)(ts1[i] - ts2[i]));
	}
	return (-1);
}
