/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:51:04 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:58:17 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*s2)
		return ((char *)s1);
	else
	{
		i = -1;
		while (s1[++i] && i < n)
		{
			if (s1[i] == s2[0])
			{
				j = 0;
				while (s1[i] && s1[i] == s2[j] && i < n)
				{
					i++;
					j++;
				}
				if (!s2[j])
					return ((char *)s1 + (i - j));
			}
		}
	}
	return (NULL);
}
