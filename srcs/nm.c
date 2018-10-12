#include "../includes/nmotool.h"


void nm(t_all *all)
{
	all->magic_number = *(int *) all->ptr;
	if (all->magic_number == MH_MAGIC_64)
	{
		ft_putendl("Fichier 64 bit");
		// display_name(all);
		// handle_64(all);
	}
	else if (all->magic_number == MH_CIGAM_64)
	{
		ft_putendl("Fichier 64 bit cigam");
	}
	else if (all->magic_number == MH_MAGIC)
	{
		ft_putendl("Fichier 32 bit   pas encore fait");
		exit(0);
	}
	else if (all->magic_number == MH_CIGAM)
	{
		ft_putendl("Fichier 32 bit cigam   pas encore fait");
	}
	else if (all->magic_number == FAT_MAGIC)
	{
		ft_putendl("Fichier FAT 32");
	}
	else if (all->magic_number == FAT_CIGAM)
	{
		ft_putendl("Fichier FAT cigam     pas encore fait");
	}
	else
	{
		ft_putstr_fd(all->name, 2);
		ft_putendl_fd(" The file was not recognized as a valid object file", 2);
		ft_putchar_fd('\n', 2);
	}
}
