/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:07:22 by achauvea          #+#    #+#             */
/*   Updated: 2014/11/08 17:00:04 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtrim_start(char *s)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	return (s);
}

static char	*ft_strtrim_end(char *s)
{
	while (*s)
		++s;
	--s;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		--s;
	return (s);
}

static char	*ft_strtrim_cut(char *start, char *end)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (start <= end)
	{
		dst = ft_strnew(end - start);
		while (start <= end)
			dst[i++] = *start++;
		dst[i] = 0;
	}
	else
	{
		dst = ft_strnew(1);
		dst[i] = 0;
	}
	return (dst);
}

char		*ft_strtrim(char const *s)
{
	char	*dst;
	char	*start;
	char	*end;

	dst = NULL;
	if (s)
	{
		start = ft_strtrim_start((char*)s);
		if (*s)
			end = ft_strtrim_end((char*)s);
		else
			end = (char*)s;
		if (start && end)
			return (ft_strtrim_cut(start, end));
	}
	return (dst);
}
