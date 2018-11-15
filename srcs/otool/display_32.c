#include "../../includes/nmotool.h"

void		affi_otool_addr_32(t_all *all, char *ptr, struct section *section)
{
	char	*res;
	int		i;

	res = NULL;
	i = -1;
	res = llx(section->addr + (ptr - (all->ptr + section->offset + all->off)));
	while ((ft_strlen(res) + ++i) < 8)
		ft_putchar('0');
	ft_putstr(res);
	free(res);
	ft_putstr("\t");
}

void		affi_otool_norm_32(char *ptr)
{
	char			*tmp;
	char			*res;

	res = NULL;
	tmp = NULL;
	if (*(ptr) < 0)
	{
		tmp = llx(swap32(*(ptr)));
		res = ft_strndup(tmp, 2);
		free(tmp);
	}
	else
		res = llx(*(ptr));
	if (ft_strlen(res) == 1)
		ft_putchar('0');
	ft_putstr(res);
	free(res);
}

char		*affi_otool_ptr_32(t_all *all, struct section *section)
{
	if (all->bonus_d)
		ft_putendl("Contents of (__DATA,__data) section");
	else
		ft_putendl("Contents of (__TEXT,__text) section");
	return ((char*)(all->ptr) + section->offset + all->off);
}

void		affi_otool_32(t_all *all, struct section *section)
{
	char			*ptr;
	uint64_t		i;
	int				pad;

	i = -1;
	pad = 0;
	ptr = affi_otool_ptr_32(all, section);
	while (++i < section->size)
	{
		if ((pad = (pad == 16 ? 0 : pad)) == 0)
			affi_otool_addr_32(all, ptr, section);
		affi_otool_norm_32(ptr);
		ptr++;
		affi_otool_pad(all, &pad);
	}
	affi_otool_nb(pad);
}
