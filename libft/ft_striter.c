/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:59:16 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 16:55:25 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	if (s && f)
	{
		i = -1;
		while (s[++i])
			(*f)(&s[i]);
	}
}
