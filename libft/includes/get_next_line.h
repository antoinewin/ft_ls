/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:21:42 by achauvea          #+#    #+#             */
/*   Updated: 2014/12/04 15:01:45 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_save
{
	struct s_save	*prv;
	struct s_save	*nxt;
	int				fd;
	char			*read;
	char			*save;
	char			*mem;
	int				iread;
}				t_save;
int				ft_gnl(int const fd, char **line);
#endif
