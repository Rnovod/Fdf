# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 14:27:39 by rnovodra          #+#    #+#              #
#    Updated: 2018/02/10 14:28:21 by rnovodra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft.a

OBJ = main.o \
		ft_open_read.o \
		ft_new_struct.o \
		fdf.o \
		ft_record.o \
		ft_creat_img_and_put.o \
		ft_brezenhem.o \
		ft_go.o \
		ft_rot.o \
		ft_gradient.o \
		ft_change_color.o \
		ft_copy_matrix.o \
		ft_info.o \
		ft_put_to_centr.o \
		ft_free_all.o \
		ft_error.o \
		ft_find_z.o \
		ft_procent.o \
		ft_check_argumets.o \
		ft_instructions.o \
		ft_validation.o

FLAGS = -Wall -Werror -Wextra

GRAPH = -framework OpenGL -framework AppKit -lmlx

CC = gcc

all : $(LIBFT) $(NAME)

$(LIBFT) :
	make all -C libft/

$(NAME) : $(OBJ)
	$(CC) -o fdf $(GRAPH) $(OBJ) libft/$(LIBFT)

%.o : %.c
	$(CC) -c -o $@ $< $(FLAGS)

clean :
	rm -rf $(OBJ)
	make clean -C libft/

fclean : clean
	rm -rf $(NAME)
	make fclean -C libft/

re : fclean all

.PHONY: all fclean clean re 
