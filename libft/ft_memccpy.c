/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:32:04 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:41:53 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*mdst;
	char	*msrc;
	size_t	i;

	i = 0;
	mdst = (char*)dst;
	msrc = (char*)src;
	while (i < n)
	{
		mdst[i] = msrc[i];
		if ((char)c == mdst[i])
			return ((void*)&mdst[i + 1]);
		i++;
	}
	return (NULL);
}
