/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:08:55 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:41:23 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number_i(int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static void	ft_itoa_putnbr(char *buff, int pos, int n)
{
	if (n >= 10 || n <= -10)
	{
		if (n > 0)
			buff[pos] = (n % 10) + '0';
		else
			buff[pos] = -(n % 10) + '0';
		ft_itoa_putnbr(buff, pos - 1, n / 10);
	}
	else
	{
		if (n > 0)
			buff[pos] = n + '0';
		else
			buff[pos] = -n + '0';
	}
}

char		*ft_itoa(int n)
{
	char	*dst;
	int		nbr;

	dst = NULL;
	nbr = ft_number_i(n);
	dst = (char *)ft_memalloc(nbr + (n < 0 ? 2 : 1));
	if (n < 0)
	{
		dst[0] = '-';
		ft_itoa_putnbr(&dst[1], nbr - 1, n);
	}
	else
		ft_itoa_putnbr(dst, nbr - 1, n);
	if (n < 0)
		dst[nbr + 1] = 0;
	else
		dst[nbr] = 0;
	return (dst);
}
