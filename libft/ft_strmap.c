/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:42:39 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:56:50 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char *s, char (*f)(char))
{
	int		i;
	char	*dst;

	if (s && f)
	{
		dst = ft_strnew(ft_strlen(s) + 1);
		i = -1;
		while (s[++i])
			dst[i] = (*f)(s[i]);
		dst[i] = 0;
		return (dst);
	}
	return (NULL);
}
