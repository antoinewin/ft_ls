/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:05:57 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:44:57 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*mdst;
	char	*msrc;
	size_t	i;

	i = -1;
	mdst = (char*)dst;
	msrc = (char*)src;
	while (++i < n)
	{
		mdst[i] = msrc[i];
	}
	return (dst);
}
