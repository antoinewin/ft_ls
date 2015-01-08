/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:06:32 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/19 09:36:43 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*dst;

	dst = NULL;
	if (size)
	{
		if ((dst = (void*)malloc(size + 1)) == NULL)
			return (NULL);
		ft_bzero(dst, size + 1);
	}
	return (dst);
}
