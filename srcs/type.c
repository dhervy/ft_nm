#include "../includes/nmotool.h"

char		*all_type_5(char *segname, char *sectname, uint8_t n_type)
{
	if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__noptrbss"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__noptrdata"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__OBJC") && !ft_strcmp(sectname, "__class"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	return (ft_strdup("?"));
}

char		*all_type_4(char *segname, char *sectname, uint8_t n_type)
{
	if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__objc_const"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") &&\
	!ft_strcmp(sectname, "__interpose"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__crash_info"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__objc_nlclslist__DATA"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__program_vars"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__dyld"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__constrw"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__v_zone"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else
		return (all_type_5(segname, sectname, n_type));
}

char		*all_type_3(char *segname, char *sectname, uint8_t n_type)
{
	if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__typelink"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__common"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") &&\
	!ft_strcmp(sectname, "__xcrun_shim"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") &&\
	!ft_strcmp(sectname, "__objc_ivar"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__objc_msg_break__DATA"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__objc_opt_rw"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && \
	!ft_strcmp(sectname, "__objc_data"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__const"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else
		return (all_type_4(segname, sectname, n_type));
}

char		*all_type_2(char *segname, char *sectname, uint8_t n_type)
{
	if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__const"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__info_plist"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__ustring"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__rodata"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__objc_opt_ro"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__itablink"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__gopclntab"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__gosymtab"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else
		return (all_type_3(segname, sectname, n_type));
}

char		*all_type(char *segname, char *sectname, uint8_t n_type)
{
	if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__bss"))
		return (ft_strdup(n_type & N_EXT ? "B" : "b"));
	else if (!ft_strcmp(segname, "__DATA") && !ft_strcmp(sectname, "__data"))
		return (ft_strdup(n_type & N_EXT ? "D" : "d"));
	else if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__text"))
		return (ft_strdup(n_type & N_EXT ? "T" : "t"));
	else if (!ft_strcmp(segname, "__TEXT") && !ft_strcmp(sectname, "__cstring"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") &&\
	!ft_strcmp(sectname, "__gcc_except_tab__TEXT"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__objc_classname__TEXT"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__objc_methtype"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else if (!ft_strcmp(segname, "__TEXT") && \
	!ft_strcmp(sectname, "__objc_methname"))
		return (ft_strdup(n_type & N_EXT ? "S" : "s"));
	else
		return (all_type_2(segname, sectname, n_type));
}
