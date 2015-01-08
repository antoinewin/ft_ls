/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:43:14 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 17:29:35 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_splitstr(char **tab, char *s, char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		while (*s == c && *s)
			++s;
		if ((tab[i] = ft_strdupc(s, c)) == NULL)
			return (0);
		while (*s != c && *s)
			++s;
		++i;
	}
	tab[i] = 0;
	return (1);
}

static int	ft_split_count(char *s, char c)
{
	int		i;

	i = 0;
	while (*s == c)
		++s;
	while (*s)
	{
		while (*s != c && *s)
			++s;
		while (*s == c && *s)
			++s;
		++i;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dst;
	int		len;

	dst = NULL;
	if (s)
	{
		len = ft_split_count((char*)s, c);
		if ((dst = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
			return (NULL);
		if (ft_splitstr(dst, (char*)s, c, len))
			return (dst);
		else
		{
			free(dst);
			dst = NULL;
		}
	}
	return (dst);
}
