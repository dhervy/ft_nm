#include "../../includes/nmotool.h"

int			otool_section_32_norm(t_all *all, struct load_command *load_command)
{
	struct segment_command	*seg_command;
	void					*section_ptr;
	struct section			*section;
	uint32_t				nsect;

	seg_command = (struct segment_command *)load_command;
	section_ptr = (void *)(seg_command + 1);
	nsect = -1;
	while (++nsect < seg_command->nsects)
	{
		section = (struct section *)section_ptr;
		if ((all->bonus_d && !ft_strcmp(section->segname, "__DATA") &&\
		!ft_strcmp(section->sectname, "__data")) || (!all->bonus_d && \
		!ft_strcmp(section->segname, "__TEXT") &&\
		!ft_strcmp(section->sectname, "__text")))
		{
			affi_otool_32(all, section);
			return (1);
		}
		section_ptr += sizeof(struct section);
	}
	return (0);
}

void		otool_section_32(t_all *all)
{
	struct load_command		*load_command;
	struct mach_header		*mach_header;
	size_t					segment_offset;
	uint32_t				i;

	i = -1;
	segment_offset = sizeof(struct mach_header);
	mach_header = (struct mach_header *)((uintptr_t)all->ptr + all->off);
	while (++i < mach_header->ncmds)
	{
		load_command = (struct load_command *)((uint8_t *)mach_header\
		+ segment_offset);
		if (load_command->cmd == LC_SEGMENT)
			if (otool_section_32_norm(all, load_command) == 1)
				return ;
		segment_offset += load_command->cmdsize;
	}
	return ;
}

void handle_32(t_all *all)
{
	int						i;
	struct mach_header	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	all->cpu = 32;
	header = (struct mach_header *)((uintptr_t)all->ptr + all->off);
	all->ncmds = header->ncmds;
	i = 0;
	lc = (void *)all->ptr + sizeof(struct mach_header) + all->off;
	while (i < all->ncmds)
	{
		if (check_corrompu(all, lc) == 1)
			return ;
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			all->stroff = (void*)all->ptr + sym->stroff + all->off;
			otool_section_32(all);
		}
		lc = (void *) lc + lc->cmdsize;
		i++;
	}
}