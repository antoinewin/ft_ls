/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:46:08 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:53:06 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = -1;
	while (src[++i])
	{
		dst[i] = src[i];
	}
	dst[i] = src[i];
	return (dst);
}
