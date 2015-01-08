/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:36:54 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:44:35 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ms;
	size_t	i;

	ms = (char *)s;
	i = 0;
	if (ms)
	{
		while (i < n)
		{
			if (ms[i] == (char)c)
				return (&ms[i]);
			i++;
		}
	}
	return (NULL);
}
