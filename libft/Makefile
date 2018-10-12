# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhervy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 17:30:32 by dhervy            #+#    #+#              #
#    Updated: 2017/03/06 02:05:13 by dhervy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c  ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
	ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c ft_strncmp.c \
	ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c \
	ft_toupper.c ft_strlcat.c ft_isspace.c ft_memalloc.c ft_strnew.c \
	ft_strclr.c ft_strequ.c ft_strnequ.c ft_strjoin.c ft_strtrim.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strdel.c ft_itoa.c \
	ft_charcat.c ft_memdel.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strsub.c ft_strsplit.c ft_strndup.c ft_strtrimi.c \
	ft_lstnew.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c \
	ft_lstmap.c ft_puttabstr.c ft_strrev.c ft_strjoinfree.c ft_strdupfree.c \
	ft_countint.c ft_decimaltobase.c ft_putspace.c ft_counttab.c ft_exiterror.c\
	get_next_line.c ft_tabdup.c ft_hexatoint.c ft_tablen.c ft_tabdupfree.c ft_tabndup.c \
	ft_tabndupfree.c ft_tabfree.c ft_putspace_fd.c ft_putnstr.c ft_putcolor.c \
	ft_tabnfree.c ft_ctoi.c

SRCO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean:
	rm -rf $(SRCO)

fclean: clean
	rm -rf $(NAME)

re: fclean all
