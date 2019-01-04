# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/27 16:45:23 by dlenskyi          #+#    #+#              #
#    Updated: 2018/12/29 21:21:40 by dlenskyi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJECT = $(SRC:.c=.o)
SRC = ft_lstiter.c	ft_putendl.c ft_strequ.c ft_strnstr.c \
ft_lstmap.c	ft_putendl_fd.c	ft_striter.c ft_strrchr.c \
ft_atoi.c	ft_lstnew.c	ft_putnbr.c	ft_striteri.c ft_strsplit.c \
ft_bzero.c	ft_memalloc.c ft_putnbr_fd.c ft_strjoin.c ft_strstr.c \
ft_isalnum.c ft_memccpy.c ft_putstr.c ft_strlcat.c ft_strsub.c \
ft_isalpha.c ft_memchr.c ft_putstr_fd.c	ft_strlen.c	ft_strtrim.c \
ft_isascii.c ft_memcmp.c ft_strcat.c ft_strmap.c ft_tolower.c \
ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strmapi.c ft_toupper.c \
ft_isprint.c ft_memdel.c ft_strclr.c ft_strncat.c ft_isdigit_valid.c \
ft_itoa.c ft_memmove.c ft_strcmp.c ft_strncmp.c ft_isdigit_base.c \
ft_lstadd.c	ft_memset.c	ft_strcpy.c	ft_strncpy.c ft_max.c ft_min.c \
ft_lstdel.c	ft_putchar.c ft_strdel.c ft_strnequ.c ft_isprefix.c \
ft_lstdelone.c	ft_putchar_fd.c	ft_strdup.c	ft_strnew.c ft_del_strsplit.c\
ft_do_op.c ft_strrev.c ft_realloc.c ft_swap.c ft_fillmatrix.c \
ft_strndup.c ft_itoa_base.c get_next_line.c ft_sqrt.c ft_delmatrix.c \
ft_printf.c print_spec_udi.c print_spec_p.c if_zero_minus.c \
set_color.c validate_params.c manage_spec.c manage_spec2.c \
print_spec_cs.c print_spec_box.c print_spec_nonvalid.c print_spec_f.c \
ft_str_toupper.c ft_ltoa_base_u.c ft_ltoa_u.c ft_ltoa.c ft_atoi_base.c

HEADER = includes

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror -I$(HEADER) $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECT)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
