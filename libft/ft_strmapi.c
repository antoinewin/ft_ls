/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:54:50 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:56:59 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	if (s && f)
	{
		dst = ft_strnew(ft_strlen(s) + 1);
		i = -1;
		while (s[++i])
			dst[i] = (*f)(i, s[i]);
		dst[i] = 0;
		return (dst);
	}
	return (NULL);
}
