# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 17:00:59 by rnovodra          #+#    #+#              #
#    Updated: 2017/11/17 19:43:42 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = ft_lstiter.o \
	ft_putnbr_fd.o \
	ft_strmapi.o \
	ft_lstmap.o \
	ft_putstr.o \
	ft_strncat.o \
	ft_lstnew.o \
	ft_putstr_fd.o \
	ft_strncmp.o \
	ft_atoi.o \
	ft_memalloc.o \
	ft_strcat.o \
	ft_strncpy.o \
	ft_bubsort_tab.o \
	ft_memccpy.o \
	ft_strchr.o \
	ft_strnequ.o \
	ft_bzero.o \
	ft_memchr.o \
	ft_strclen.o \
	ft_strnew.o \
	ft_clist.o	\
	ft_memcmp.o	\
	ft_strclr.o	\
	ft_strnstr.o \
	ft_count_digits.o \
	ft_memcpy.o \
	ft_strcmp.o	\
	ft_strrchr.o \
	ft_count_words.o \
	ft_memdel.o \
	ft_strcpy.o	\
	ft_strsplit.o \
	ft_isalnum.o \
	ft_memmove.o \
	ft_strdel.o \
	ft_strstr.o \
	ft_isalpha.o \
	ft_memset.o \
	ft_strdup.o \
	ft_strsub.o \
	ft_isascii.o \
	ft_pow.o \
	ft_strequ.o \
	ft_strtrim.o \
	ft_isdigit.o \
	ft_prime.o \
	ft_striter.o \
	ft_swap.o \
	ft_isprint.o \
	ft_putchar.o \
	ft_striteri.o \
	ft_tolower.o \
	ft_itoa.o \
	ft_putchar_fd.o \
	ft_strjoin.o \
	ft_toupper.o \
	ft_lstadd.o \
	ft_putendl.o \
	ft_strlcat.o \
	ft_lstdel.o	\
	ft_putendl_fd.o \
	ft_strlen.o \
	ft_lstdelone.o \
	ft_putnbr.o \
	ft_strmap.o \
	ft_free.o \
	ft_putarr.o \
	ft_arrcpy.o \
	ft_arrnew.o \
	ft_arrlen.o \
	ft_arrdup.o \
	ft_arrcat.o \
	ft_arrjoin.o \
	get_next_line.o \
	ft_atoi_base.o \
	ft_itoa_base.o

FLAGS = -Wall -Werror -Wextra

CC = gcc

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) -c -o $@ $< $(FLAGS)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re 
