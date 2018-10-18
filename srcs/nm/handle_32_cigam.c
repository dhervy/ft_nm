#include "../../includes/nmotool.h"

void	find_type_32_cigam(t_all *all, t_cmd *cmd, struct nlist *element)
{
	all->cpu = all->cpu;
	if ((element->n_type & N_TYPE) == N_UNDF)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "U" : "u");
	else if ((element->n_type & N_TYPE) == N_ABS)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "A" : "a");
	else if ((element->n_type & N_TYPE) == N_INDR)
		cmd->type = ft_strdup(element->n_type & N_EXT ? "I" : "i");
	else if ((element->n_type & N_TYPE) == N_SECT)
		cmd->type = handle_32_cigam_findsec(all, element);
	else {
		cmd->type = ft_strdup("?");
	}
}

void		insert_output_32_cigam(t_all *all, int nsyms, int symoff, int stroff)
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
		add_list_32_cigam(&cmds, &elements[i], all);
		i++;
	}
	display_lst(&cmds, all);
}

void		handle_32_cigam(t_all *all)
{
	struct mach_header		*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	int						i;

	i = 0;
    all->cpu = 32;
	all->cigam = 1;
	header = (struct mach_header *)((uintptr_t)all->ptr + all->off);
	all->ncmds = swap32(header->ncmds);
	lc = (void*)((uintptr_t)all->ptr + all->off) + sizeof(struct mach_header);
	while (i < all->ncmds)
	{
		if (check_corrompu(all, lc) == 1)
			return ;
		if (swap32(lc->cmd) == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			insert_output_32_cigam(all, swap32(sym->nsyms), swap32(sym->symoff), swap32(sym->stroff));
			break ;
		}
		lc = (void *)lc + swap32(lc->cmdsize);
        i++;
	}
}

char	*handle_32_cigam_findsec_norm(struct nlist *element,\
	struct load_command *load_command, int *nsec)
{
	struct segment_command	*seg_command;
	struct section			*sectio;
	void					*section_ptr;
	uint32_t				nsect;

	nsect = -1;
	seg_command = (struct segment_command *)load_command;
	section_ptr = (void *)(seg_command + 1);
	while (++nsect < swap32(seg_command->nsects))
	{
		sectio = (struct section *)section_ptr;
		if (*nsec == element->n_sect)
			return (all_type(sectio->segname, sectio->sectname, element->n_type));
		section_ptr += sizeof(struct section);
		(*nsec)++;
	}
	return (NULL);
}


char	*handle_32_cigam_findsec(t_all *all, struct nlist *element)
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
	while (++i < swap32(mach_header->ncmds))
	{
		load_command = (struct load_command *)((uint8_t *)mach_header\
		+ segment_offset);
		if (swap32(load_command->cmd) == LC_SEGMENT)
		{
			if ((all->res = handle_32_cigam_findsec_norm(element, load_command,\
				&nsec)) != NULL)
				return (all->res);
		}
		segment_offset += swap32(load_command->cmdsize);
	}
	return (ft_strdup("?"));
}