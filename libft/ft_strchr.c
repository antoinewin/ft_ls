/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:01:17 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:51:59 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ms;

	ms = (char*)s;
	if (ms)
	{
		while (*ms)
		{
			if (*ms == (char)c)
				return (ms);
			++ms;
		}
		if ((char)c == 0)
			return (ms);
	}
	return (NULL);
}
