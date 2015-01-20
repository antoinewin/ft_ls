/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:19:39 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 12:18:45 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_error_before(t_error *error1, t_error *error2)
{
	error1->nxt = error2;
	error2->prv = error1;
}

void	ls_error_between(t_error *error, t_error *error1, t_error *error2)
{
	error1->nxt = error;
	error->prv = error1;
	error->nxt = error2;
	error2->prv = error;
}

t_error	*ls_place_error_name(t_error *error, t_error *errors, int off)
{
	if (off)
		while (ft_strcmp(error->name, errors->name) > 0 && error->erno == errors->erno
				&& errors->nxt != NULL)
			errors = errors->nxt;
	else
		while (ft_strcmp(error->name, errors->name) > 0 && errors->nxt != NULL)
			errors = errors->nxt;
	if (errors->prv == NULL && ft_strcmp(error->name, errors->name) <= 0)
		ls_error_before(error, errors);
	else if (errors->nxt == NULL && ft_strcmp(error->name, errors->name) >= 0)
		ls_error_before(errors, error);
	else
		ls_error_between(error, errors->prv, errors);
	return (errors);
}

t_error	*ls_place_error(t_error *error, t_error *errors, int off)
{
	if (!errors->name)
		return (error);
	while (errors->prv)
		errors = errors->prv;
	if (off)
	{
		while (error->erno > errors->erno && errors->nxt != NULL)
			errors = errors->nxt;
		if (errors->prv == NULL && error->erno < errors->erno)
			ls_error_before(error, errors);
		else if (errors->nxt == NULL && error->erno > errors->erno)
			ls_error_before(errors, error);
		else if (error->erno == errors->erno)
			ls_place_error_name(error, errors, off);
		else
			ls_error_between(error, errors->prv, errors);
	}
	else
		ls_place_error_name(error, errors, off);
	return (errors);
}

t_error	*ls_error(t_error *errors, char *name, int off)
{
	t_error	*error;

	error = ft_create_error();
	if ((error->name = (char*)ft_memalloc(ft_strlen(name))) == NULL)
		ft_error("ft_ls", "malloc", 1);
	error->name = ft_strcpy(error->name, name);
	if (off)
		error->erno = errno;
	errors = ls_place_error(error, errors, off);
	return (errors);
}
