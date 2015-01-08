/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:16:12 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:58:58 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ms;

	ms = (char*)s;
	if (ms)
	{
		while (*ms)
			++ms;
		while (ms >= s)
		{
			if (*ms == (char)c)
				return (ms);
			--ms;
		}
	}
	return (NULL);
}
