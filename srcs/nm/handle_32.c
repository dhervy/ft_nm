/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:17:50 by dhervy            #+#    #+#             */
/*   Updated: 2018/11/16 18:17:52 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/nmotool.h"

void		insert_output_32(t_all *all, int nsyms, int symoff, int stroff)
{
	t_cmd			*cmds;
	int				i;
	struct nlist	*elements;

	i = 0;
	cmds = NULL;
	elements = (void*)all->ptr + symoff + all->off;
	all->stroff = (void*)all->ptr + stroff + all->off;
	while (i < nsyms)
	{
		if (check_corrompu(all, &elements[i]) == 1)
			return ;
		add_list_32(&cmds, &elements[i], all);
		i++;
	}
	display_lst(&cmds, all);
}

void		find_type_32(t_all *all, t_cmd *cmd, struct nlist *element)
{
	all->cpu = all->cpu;
	if ((element->n_type & N_TYPE) == N_UNDF)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "U" : "u");
	else if ((element->n_type & N_TYPE) == N_ABS)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "A" : "a");
	else if ((element->n_type & N_TYPE) == N_INDR)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "I" : "i");
	else if ((element->n_type & N_TYPE) == N_SECT)
		cmd->type = handle_32_findsec(all, element);
	else
		cmd->type = ft_strdup("?");
}

void		handle_32(t_all *all)
{
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	int						i;

	all->cpu = 32;
	header = (struct mach_header *)((uintptr_t)all->ptr + all->off);
	all->ncmds = header->ncmds;
	i = 0;
	lc = (void*)all->ptr + sizeof(struct mach_header) + all->off;
	while (i < all->ncmds)
	{
		if (check_corrompu(all, lc) == 1)
			return ;
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			insert_output_32(all, sym->nsyms, sym->symoff, sym->stroff);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
}

char		*handle_32_findsec_norm(struct nlist *element,\
	struct load_command *load_command, int *nsec)
{
	struct segment_command	*seg_command;
	struct section			*sectio;
	void					*section_ptr;
	uint32_t				nsect;

	nsect = -1;
	seg_command = (struct segment_command *)load_command;
	section_ptr = (void *)(seg_command + 1);
	while (++nsect < seg_command->nsects)
	{
		sectio = (struct section *)section_ptr;
		if (*nsec == element->n_sect)
		{
			return (all_type(sectio->segname,\
			sectio->sectname, element->n_type));
		}
		section_ptr += sizeof(struct section);
		(*nsec)++;
	}
	return (NULL);
}

char		*handle_32_findsec(t_all *all, struct nlist *element)
{
	struct mach_header		*mach_header;
	struct load_command		*load_command;
	size_t					segment_offset;
	int						nsec;
	uint32_t				i;

	i = -1;
	all->res = NULL;
	nsec = 1;
	mach_header = (struct mach_header *)((uintptr_t)all->ptr + all->off);
	segment_offset = sizeof(struct mach_header);
	while (++i < mach_header->ncmds)
	{
		load_command = (struct load_command *)((uint8_t *)mach_header\
		+ segment_offset);
		if (load_command->cmd == LC_SEGMENT)
		{
			if ((all->res = handle_32_findsec_norm(element, load_command,\
				&nsec)) != NULL)
				return (all->res);
		}
		segment_offset += load_command->cmdsize;
	}
	return (ft_strdup("?"));
}
