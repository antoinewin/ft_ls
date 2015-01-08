/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 09:53:20 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:45:25 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*msrc;

	if (dst && src)
	{
		msrc = ft_strnew(len);
		ft_memcpy(msrc, src, len);
		ft_memcpy(dst, msrc, len);
		free(msrc);
	}
	return (dst);
}
