/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 08:18:30 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:45:35 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*m;
	size_t			i;

	i = -1;
	m = (unsigned char*)b;
	while (++i < len)
	{
		m[i] = (unsigned char)c;
	}
	return (b);
}
