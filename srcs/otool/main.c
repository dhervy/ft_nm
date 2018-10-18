#include "../../includes/nmotool.h"

void init_struct(t_all *all)
{
	all->ptr = NULL;
	all->arch_ppc = 0;
	all->stroff = 0;
	all->cpu = 0;
	all->cigam = 0;
	all->off = 0;
	all->fd = 0;
	all->magic_number = 0;
	all->ncmds = 0;
	all->name = NULL;
}

int file_handle(t_all *all, char *name)
{
	if (name[0] == '-')
		return (0);
	if ((all->fd = open(name, O_RDONLY)) < 0)
	{
		ft_putendl_fd("Erreur (open) : impossible d\'ouvrir l\'executable.", 2);
		return(0);
	}
	if (fstat(all->fd, &all->file_stat) < 0)
	{
		ft_putendl_fd("Erreur (fstat) : impossible de lire l\'executable.", 2);
		return(0);
	}
	if ((all->ptr = mmap(0, all->file_stat.st_size, PROT_READ, MAP_PRIVATE, all->fd, 0)) == MAP_FAILED)
	{
		ft_putendl_fd("Erreur (nmap) : fail.", 2);
		return(0);
	}
	all->name = name;
	return(1);


void		ft_otool_norm(t_all *all)
{
	if ((unsigned int)(all->magic_number) == FAT_CIGAM)
	{
		all->cpu = 32;
		// handle_fat_32(all);
	}
	else
	{
		ft_putstr_fd(all->name, 2);
		ft_putendl_fd(" The file was not recognized as a valid object file", 2);
		ft_putendl_fd("", 2);
	}
	return ;
}

void		ft_otool(t_all *all)
{
	if ((unsigned int)(all->magic_number = *(int*)all->ptr) == MH_MAGIC_64)
	{
		all->cpu = 64;
		ft_putstr(all->name);
		ft_putendl(":");
		handle_64(all);
	}
	else if ((unsigned int)(all->magic_number) == MH_MAGIC)
	{
		all->cpu = 32;
		ft_putstr(all->name);
		ft_putendl(":");
		// handle_32(all);
	}
	else
		ft_otool_norm(all);
}}

int main(int ac, char **av)
{
	t_all 		all;
	int			i;

	if (ac < 2)
	{
		ft_putendl_fd("please give me an arg", 2);
		return (0);
	}

	i = 0;
	all.ac = ac;
	init_struct_bonus_otool(&all);
	parse_otool_bonus(&all, av, ac);
	while (++i < ac)
	{
		init_struct(&all);
		if (file_handle(&all, av[i])) {
			otool(&all);
			if (munmap(all.ptr, all.file_stat.st_size) < 0)
				ft_putendl_fd("Erreur (munmap) : fail.", 2);
			if (all.fd >= 0)
				close(all.fd);
		}
	}
}
