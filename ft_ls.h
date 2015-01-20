/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:32:41 by achauvea          #+#    #+#             */
/*   Updated: 2015/01/20 12:07:16 by achauvea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>

# define DT_UNKNOWN	0
# define DT_FIFO	1
# define DT_CHR		2
# define DT_DIR		4
# define DT_BLK		6
# define DT_REG		8
# define DT_LNK		10
# define DT_SOCK	12
# define DT_WHT		14
# define LS_MAJOR(x) ((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define LS_MINOR(x) ((int32_t)((x) & 0xffffff))

typedef struct	s_opt
{
	int		l;
	int		re;
	int		a;
	int		r;
	int		t;
	int		off;
}				t_opt;
typedef struct	s_elem
{
	struct s_elem	*prv;
	struct s_elem	*nxt;
	char			*name;
	char			*path;
	time_t			date;
	int				sub;
	mode_t			st_mode;
	off_t			st_size;
	nlink_t			st_nlink;
	quad_t			st_blocks;
	dev_t			st_rdev;
	char			*username;
	char			*groupname;
}				t_elem;
typedef struct	s_error
{
	struct s_error	*prv;
	struct s_error	*nxt;
	char			*name;
	int				erno;
}				t_error;
typedef struct	s_size
{
	quad_t			total;
	int				size;
	int				groupsize;
	int				usersize;
	int				linksize;
	int				min;
	int				maj;
}				t_size;
t_opt			*ft_create_opt(void);
t_elem			*ft_create_elem(void);
t_error			*ft_create_error(void);
t_size			*ft_create_size(void);
void			ls_add_elem(char *path, t_elem *elem, struct stat *buf, struct dirent *entry);
t_elem			*ls_place_elem(t_elem *elem, t_elem *list, t_opt *opt);
int				ls_arguments(int ac, char **av, t_opt *opt);
int				ls_dir_list(char *path, t_opt *opt, int ac, char *name);
char			*ft_istrchr(char *str);
DIR				*ls_open_file(char *name, char *path);
void			ft_print(t_size *size, t_elem *list, t_opt *opt);
void			ft_print_file(t_error *errors, t_opt *opt);
void			ft_print_permi(mode_t st_mode, int sub);
void			ft_print_int(unsigned int toprint, int size);
void			ft_print_gn(char *name, int size);
void			ft_print_lnk(t_elem *list);
void			ft_print_time(time_t date);
void			ft_print_total(t_size *size, t_opt *opt);
void			ft_print_enoent(char *name);
void			ft_print_eacces(char *path);
t_size			*ft_calcsize(t_elem *list, t_opt *opt);
void			ft_print_majmin(t_elem *list, t_size *size);
void			ls_r_on(t_elem *list, t_opt *opt);
void			ls_r_off(t_elem *list, t_opt *opt);
void			ls_recursive(t_elem *list, t_opt *opt);
void			ls_dir_r(t_error *dir, t_opt *opt, int aci);
t_error			*ls_error(t_error *errors, char *name, int off);
#endif
