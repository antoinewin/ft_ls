/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:30:41 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 17:00:58 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	else
	{
		i = -1;
		while (s1[++i])
		{
			if (s1[i] == s2[0])
			{
				j = 0;
				while (s1[i] && s1[i] == s2[j])
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
