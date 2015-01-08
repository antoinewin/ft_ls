/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:26:40 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:38:13 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		ret;
	int		is_neg;

	is_neg = 0;
	ret = 0;
	str = (char*)str;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
				|| *str == '\v' || *str == '\f')
			++str;
		if (*str == '-')
			is_neg = 1, ++str;
		else if (*str == '+')
			++str;
		while (*str >= '0' && *str <= '9')
		{
			ret += *str++ - '0';
			if (*str >= '0' && *str <= '9')
				ret *= 10;
		}
	}
	return (is_neg ? -ret : ret);
}
