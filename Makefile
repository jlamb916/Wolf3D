# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolam <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 00:53:07 by jolam             #+#    #+#              #
#    Updated: 2019/05/24 17:25:17 by knguyen-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c\
	  setup.c\
	  map.c\
	  move.c\
	  calc.c\
	  helper.c\
	  hooks.c\
	  draw_frame.c\
	  strafe.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

GCC = gcc -g -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBINC = -I ./libft/includes
LIBLINK = -L ./libft -lft

MLX = ./minilibx/libmlx.a
MLXINC = -I ./minilibx
MLXLINK = -L ./minilibx -lmlx -framework OpenGl -framework Appkit

SRCDIR = ./srcs/
INCDIR = ./includes/
OBJDIR = ./objs/

all: obj libft mlx $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(GCC) $(LIBINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

mlx: $(MLX)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx

$(NAME): $(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(MLXLINK) $(LIBLINK)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
