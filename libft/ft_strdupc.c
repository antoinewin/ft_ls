/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:50:47 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:54:55 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupc(const char *s1, char c)
{
	char	*dst;

	dst = NULL;
	if (s1)
	{
		dst = ft_strnew(ft_strlenc(s1, c) + 1);
		ft_strcpyc(dst, s1, c);
	}
	return (dst);
}
