/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:48:42 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 17:00:45 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	slen;

	dst = NULL;
	if (s)
	{
		slen = ft_strlen(s);
		if (!slen || start > slen || len > slen)
			return (NULL);
		dst = ft_strnew(len + 1);
		i = 0;
		while (i < len)
			dst[i++] = s[start++];
		dst[i] = 0;
	}
	return (dst);
}
