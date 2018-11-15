#include "../../includes/nmotool.h"

void		affi_otool_nb(int pad)
{
	if (pad != 16)
		ft_putchar('\n');
}

void		affi_otool_pad(t_all *all, int *pad)
{
	(*pad)++;
	if (!all->arch_ppc || !((*pad) % 4))
		ft_putchar(' ');
	if ((*pad) == 16)
		ft_putchar('\n');
}