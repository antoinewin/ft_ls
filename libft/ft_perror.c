/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:42:08 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/03 14:45:31 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	ft_perror(char *name, char *error, int iexit)
{
	if (name)
		ft_putstr(name), ft_putstr(": ");
	perror(error);
	if (iexit)
		exit(iexit);
}
