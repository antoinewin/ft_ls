/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:07:31 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/19 10:17:21 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_error(char *fonction, char *fichier, int ex)
{
	ft_putstr(fonction);
	ft_putstr(": ");
	perror(fichier);
	if (ex)
		exit(0);
}
