# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/23 15:36:22 by myoung            #+#    #+#              #
#    Updated: 2023/10/26 11:24:29 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgfx.a

FILES =		draw.c			# Draw points and lines
FILES +=	mx_op.c			# Matrix functions: bzero id mult scale trans
FILES +=	mx_r.c			# Matrix functions: rotation
FILES +=	vertex.c		# Vertex creation:
FILES +=	image.c			# easier image creation
FILES +=	color.c			# color table

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix srcs/, $(FILES))
OBJS = $(addprefix build/, $(FILES:.c=.o))

GFX = -I .
FT = -I ../libft
MLX = -I ../minilibx

.PHONY: all re clean fclean

all: $(NAME)

re: fclean all

clean:
	rm -rf build

fclean: clean
	rm -rf $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	@echo "Making $@"
	@ar rcs $(NAME) $(OBJS)

build/%.o: srcs/%.c build
	@echo "Building $@"
	@gcc $(FLAGS) $(FT) $(MLX) $(GFX) -c $< -o $@
