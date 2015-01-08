/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:13:00 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/11 14:37:21 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*dst;

	dst = NULL;
	if ((dst = (char*)malloc(size + 1 * sizeof(*dst))) == NULL)
		return (NULL);
	return (ft_memset(dst, 0, size + 1));
}
