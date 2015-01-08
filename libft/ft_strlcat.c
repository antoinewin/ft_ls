/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:12 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:56:11 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;
	size_t	len;

	if (dst && src)
	{
		len = ft_strlen(src);
		i = 0;
		i2 = 0;
		while (dst[i] && i < size)
			++i;
		if (size > 0)
			while (i < size - 1 && src[i2])
				dst[i++] = src[i2++];
		if (i2 > 0)
		{
			dst[i] = 0;
			return (len + i - i2);
		}
		return (len + i);
	}
	return (0);
}
