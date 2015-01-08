/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:55:51 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:53:23 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyc(char *dst, const char *src, char c)
{
	char	*msrc;
	char	*mdst;

	mdst = dst;
	msrc = (char*)src;
	if (msrc && mdst)
	{
		while (*msrc != c)
			*mdst++ = *msrc++;
		*mdst = 0;
	}
	return (dst);
}
