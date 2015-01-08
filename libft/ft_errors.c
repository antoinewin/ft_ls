/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 10:19:44 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/19 10:21:27 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_errors(char *fonction, char *msg, int ex)
{
	ft_putstr(fonction);
	ft_putstr(": ");
	ft_putendl(msg);
	if (ex)
		exit(0);
}
