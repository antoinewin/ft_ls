/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:58:05 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/19 09:39:39 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		y;

	dst = NULL;
	if (s1 || s2)
	{
		dst = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2));
		i = -1;
		while (s1[++i])
			dst[i] = s1[i];
		y = 0;
		while (s2[y])
		{
			dst[i++] = s2[y++];
		}
		dst[i] = 0;
	}
	return (dst);
}
