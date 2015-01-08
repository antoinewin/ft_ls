/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:41:21 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/19 13:53:12 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = NULL;
	if (*s1)
	{
		if ((dst = (char*)ft_memalloc(ft_strlen(s1))) == NULL)
			ft_errors("Malloc", "Erreur strdup", 1);
		ft_strcpy(dst, s1);
	}
	return (dst);
}
