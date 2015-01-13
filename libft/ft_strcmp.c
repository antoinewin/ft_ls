/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:04:22 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/13 11:52:21 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	if (*s1 || *s2)
	{
		if (!s1)
			return (0 - s2[0]);
		else if (!s2)
			return (0 - s1[0]);
		i = 0;
		while (s1[i] || s2[i])
		{
			if (s1[i] == s2[i])
				i++;
			else
				return (s1[i] - s2[i]);
		}
	}
	return (0);
}
