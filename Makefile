# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhervy <dhervy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/18 01:28:07 by dhervy            #+#    #+#              #
#    Updated: 2018/04/15 19:49:01 by dhervy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMENM = ft_nm
NAMEOTOOL = ft_otool

CC = clang
CFLAGS = -Wall -Werror -Wextra

NMPATH = srcs/nm/
OTOOLPATH = srcs/otool/
HPATH = includes/
CFILESNM = \
	main.c \
	list.c \
	list_64.c \
	list_32.c \
	list_32_cigam.c \
	display.c \
	nm.c \
	handle_64.c \
	handle_32.c \
	handle_32_cigam.c \
	handle_fat.c \
	tools.c \
	type.c \
	bonus.c \
	other.c \

CFILESOTOOL = \
	main.c \
	bonus.c \
	handle_64.c \
	handle_32.c \
	handle_32_cigam.c \
	handle_fat.c \
	display_64.c \
	display_32.c \
	display_32_cigam.c \
	display_tools.c \
	tools.c \

OPATHNM = obj/nm/
OPATHOTOOL = obj/otool/
OFILESNM = $(CFILESNM:.c=.o)
OFILESOTOOL = $(CFILESOTOOL:.c=.o)
OBJNM = $(addprefix $(OPATHNM), $(OFILESNM))
OBJOTOOL = $(addprefix $(OPATHOTOOL), $(OFILESOTOOL))

.PHONY: all clean fclean re

all: $(NAMENM) $(NAMEOTOOL)

$(NAMENM): $(OBJNM)
	@echo "Compiling \"$(NAMENM)\"..."
	make -C libft
	$(CC) $(CFLAGS) $(OBJNM) -o$(NAMENM) -L libft -lft
	@echo "Successful compilation! $(NAMENM)\n---"

$(OPATHNM)%.o: $(NMPATH)%.c includes/nmotool.h
	@mkdir -p $(OPATHNM)
	$(CC) $(CFLAGS) -I inc -c -o $@ $<

$(NAMEOTOOL): $(OBJOTOOL)
	@echo "Compiling \"$(NAMEOTOOL)\"..."
	make -C libft
	$(CC) $(CFLAGS) $(OBJOTOOL) -o$(NAMEOTOOL) -L libft -lft
	@echo "Successful compilation! $(NAMEOTOOL) \n---"

$(OPATHOTOOL)%.o: $(OTOOLPATH)%.c includes/nmotool.h
	@mkdir -p $(OPATHOTOOL)
	$(CC) $(CFLAGS) -I inc -c -o $@ $<

clean:
	@echo "Deleting the directory /obj..."
	make -C libft clean
	@rm -f $(OBJNM)
	@rm -f $(OBJOTOOL)
	@echo "Deletion complete !"

fclean: clean
	@echo "Deleting binary "$(NAMEOTOOL)"..."
	@echo "Deleting binary "$(NAMENM)"..."
	make -C libft fclean
	@rm -f $(NAMENM)
	@rm -f $(NAMEOTOOL)
	@echo "Deletion complete !"/

re: fclean all
