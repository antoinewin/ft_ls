/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:30:30 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:57:43 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*mdst;
	char	*msrc;

	mdst = dst;
	msrc = (char*)src;
	i = 0;
	if (mdst && msrc)
	{
		while (msrc[i] && i < n)
		{
			mdst[i] = msrc[i];
			i++;
		}
		while (i < n)
		{
			mdst[i] = 0;
			i++;
		}
	}
	return (dst);
}
