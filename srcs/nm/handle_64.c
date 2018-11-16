/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:18:00 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:18:02 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void	insert_output_64(t_all *all, int nsyms, int symoff, int stroff)
{
	t_cmd			*cmds;
	int				i;
	struct nlist_64	*elements;

	i = 0;
	cmds = NULL;
	elements = (void *)all->ptr + symoff + all->off;
	all->stroff = (void *)all->ptr + stroff + all->off;
	while (i < nsyms)
	{
		if (check_corrompu(all, &elements[i]) == 1)
			return ;
		add_list_64(&cmds, &elements[i], all);
		i++;
	}
	display_lst(&cmds, all);
}

void	find_type_64(t_all *all, t_cmd *cmd, struct nlist_64 *element)
{
	all->cpu = all->cpu;
	if ((element->n_type & N_TYPE) == N_UNDF)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "U" : "u");
	else if ((element->n_type & N_TYPE) == N_ABS)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "A" : "a");
	else if ((element->n_type & N_TYPE) == N_INDR)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "I" : "i");
	else if ((element->n_type & N_TYPE) == N_SECT)
		cmd->type = handle_64_findsec(all, element);
	else
		cmd->type = ft_strdup("?");
}

void	handle_64(t_all *all)
{
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	all->cpu = 64;
	header = (struct mach_header_64 *)((uintptr_t)all->ptr + all->off);
	all->ncmds = header->ncmds;
	i = 0;
	lc = (void *)all->ptr + sizeof(struct mach_header_64) + all->off;
	while (i < all->ncmds)
	{
		if (check_corrompu(all, lc) == 1)
			return ;
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			insert_output_64(all, sym->nsyms, sym->symoff, sym->stroff);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}

char	*handle_64_findsec_norm(struct nlist_64 *element,\
	struct load_command *load_command, int *nsec)
{
	struct segment_command_64	*seg_command;
	struct section_64			*sectio;
	void						*section_ptr;
	uint32_t					nsect;

	nsect = -1;
	seg_command = (struct segment_command_64 *)load_command;
	section_ptr = (void *)(seg_command + 1);
	while (++nsect < seg_command->nsects)
	{
		sectio = (struct section_64 *)section_ptr;
		if ((*nsec) == element->n_sect)
		{
			return (all_type(sectio->segname,\
			sectio->sectname, element->n_type));
		}
		section_ptr += sizeof(struct section_64);
		(*nsec)++;
	}
	return (NULL);
}

char	*handle_64_findsec(t_all *all, struct nlist_64 *element)
{
	struct load_command		*load_command;
	struct mach_header_64	*mach_header;
	size_t					segment_offset;
	int						nsec;
	uint32_t				i;

	nsec = 1;
	i = -1;
	all->res = NULL;
	mach_header = (struct mach_header_64 *)((uintptr_t)all->ptr + all->off);
	segment_offset = sizeof(struct mach_header_64);
	while (++i < mach_header->ncmds)
	{
		load_command = (struct load_command *)((uint8_t *)mach_header\
		+ segment_offset);
		if (load_command->cmd == LC_SEGMENT_64)
		{
			if ((all->res = handle_64_findsec_norm(element, load_command,\
			&nsec)) != NULL)
				return (all->res);
		}
		segment_offset += load_command->cmdsize;
	}
	return (ft_strdup("?"));
}
