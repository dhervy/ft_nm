/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <dhervy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:51:36 by dhervy            #+#    #+#             */
/*   Updated: 2018/04/15 19:50:30 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMOTOOL_H
# define NMOTOOL_H

# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/ranlib.h>
# include <mach-o/fat.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>
# include "../libft/libft.h"

# define ABS(x)	((x < 0) ? -(x) : (x))

typedef struct	s_all
{
	int				arch_ppc;
	int				cpu;
	int				cigam;
	uint32_t		off;
	char			*stroff;
	char			*name;
	char			*res;
	int				ac;
	char			*ptr;
	int				fd;
	int				ncmds;
	struct stat		file_stat;
	unsigned int	magic_number;
	int				bonus_a;
	int				bonus_g;
	int				bonus_p;
	int				bonus_d;
	int				bonus_r;
}					t_all;

typedef struct						s_cmd
{
	char							*name;
	char							*type;
	unsigned long long int			value;
	struct s_cmd					*next;
}									t_cmd;

void		find_type_64(t_all *all, t_cmd *cmd, struct nlist_64 *element);
void		display_name(t_all *all);
void		nm(t_all *all);
int			check_corrompu(t_all *all, void *ptr);
char		*all_type(char *segname, char *sectname, uint8_t n_type);
void		handle_64(t_all *all);
char		*handle_64_findsec(t_all *all, struct nlist_64 *element);
void		display_lst(t_cmd **begin, t_all *all);
char		*llx(unsigned long long int value);
int			bonus_p_sort(t_all *all, t_cmd **tmp, t_cmd **tmp2);
void		parse_nm_bonus(t_all *all, char **av, int ac);
void		init_struct_bonus_nm(t_all *all);
void		write_bonus_erreur(char *str, int i);
void		init_add_list(t_cmd **begin, t_cmd **tmp, t_cmd **tmp2, t_cmd **tmp3);
int			shearch_same_name(t_cmd **begin, t_cmd *this);
void		sort_lst(t_cmd **begin, t_cmd **tmp, t_cmd **tmp2, t_cmd **tmp3);
void		sort_lst2(t_cmd **tmp, t_cmd **tmp2);
void		add_list_64(t_cmd **begin, struct nlist_64 *nlist, t_all *all);
void		handle_32(t_all *all);
void		find_type_32(t_all *all, t_cmd *cmd, struct nlist *element);
void		add_list_32(t_cmd **begin, struct nlist *nlist, t_all *all);
char		*handle_32_findsec(t_all *all, struct nlist *element);
uint32_t	swap32(uint32_t a);
void		handle_32_cigam(t_all *all);
void		add_list_32_cigam(t_cmd **begin, struct nlist *nlist, t_all *all);
void		find_type_32_cigam(t_all *all, t_cmd *cmd, struct nlist *element);
char		*handle_32_cigam_findsec(t_all *all, struct nlist *element);
void		handle_fat_32(t_all *all);
char		*find_cputype(t_all *all, int nb);

void		parse_otool_bonus(t_all *all, char **av, int ac);
void		init_struct_bonus_otool(t_all *all);

#endif
