# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 21:23:27 by antoda-s          #+#    #+#              #
#    Updated: 2023/10/25 23:08:04 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fdf
MLX 		= minilibx.a
LIBFT 		= libft.a
GFX 		= libgfx.a

LFT_PATH 	= ./libft/
GFX_PATH 	= ./libgfx/
MLX_PATH 	= ./minilibx/
INCLUDES 	= ./include/
SRCDIR 		= srcs/
OBJSDIR 	= build/

FILES	=	main.c
FILES	+=	fdf.c			# Top level fdf functions
FILES	+=	parse.c			# Parse out the map files into vertexs
FILES	+=	zoom.c			# Zoom and translate functions
FILES	+=	wireframe.c		# view and local_to_world_to_aligned_to_projected
FILES	+=	hooks.c			# Loop, exit, expose and key hooks
FILES	+=	draw_fdf.c		# Connect the vertexs with lines
FILES	+=	color_fdf.c		# color random for fdf
FILES	+=	toggle_keys.c	# toggle keys

#close.c
#color.c \
#draw.c \
#error.c \
#init_utils.c \
#init.c \
#key_handle.c \
#menu.c \
#project.c \
#read.c \
#render.c \
#rotate.c \
#transform.c \
#utils.c

SRC = $(addprefix $(SRCDIR), $(FILES))
OBJ = $(addprefix $(OBJSDIR), $(FILES:.c=.o))


#compilation
CF 			= -Wall -Wextra -Werror -g
CC 			= cc
# 1 MLX_CF 		= -lm -lbsd -lmlx -lXext -lX11
# 2 MLX_CF 		= -lm -lbsd -lXext -lX11
MLX_CF 		= -lm -lXext -lX11
I_HEADER	= -I include
I_MLX 		= -I minilibx
I_LIBFT 	= -I libft
I_GFX 		= -I libgfx
LNK_LIBFT 	= -L $(LFT_PATH) -lft
LNK_MLX 	= -L $(MLX_PATH) -lmlx
LNK_GFX 	= -L $(GFX_PATH) -lgfx

LEAKS 		= valgrind
LEAKS_FILE	= valgrind-log.txt
LF 			= --leak-check=full \
        		--show-leak-kinds=all \
        		--track-origins=yes \
        		--verbose \
        		--log-file=$(LEAKS_FILE) \
        		./fdf maps/42.fdf

#common commands
RM =rm -f

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
CYN		:= \33[1;36m
RESET	:= \033[0m
BOLD	:= \033[1m

_INFO		=	[$(YLW)INFO$(WTH)]
_SUCCESS	=	[$(GRN)DONE$(WTH)]



#rules
all: $(NAME)

$(NAME): $(GFX) $(LIBFT) $(MLX) $(OBJ)
	@printf "$(GRN)Objects ready!$(WTH)\n\n"
	@printf "\n$(CYN)Generating FdF executable...$(WTH)\n"
#1	$(CC) $(CF) $(OBJ) -L $(LFT_PATH) -L $(MLX_PATH) -lft $(MLX_CF) -o $@
#	$(CC) $(CF) $(OBJ) $(LNK_LIBFT) $(LNK_MLX) $(MLX_CF) -o $@
	$(CC) $(CF) $(OBJ) $(LNK_LIBFT) $(LNK_GFX) $(LNK_MLX) $(MLX_CF) -o $@

	@printf "$(GRN)Done!$(WTH)\n\n"

build:
	@mkdir -p $(OBJSDIR)
	@printf "\n$(CYN)Compiling source files...$(WTH)\n"

# $(OBJ): $(OBJSDIR)/%.o: $(SRCDIR)/%.c | build
$(OBJSDIR)%.o: $(SRCDIR)%.c | build
# 	@$(CC) $(CF) -I mlx_linux -I libft -I ./include -c $< -o $@
	$(CC) $(CF) -g -c $(I_GFX) $(I_MLX) $(I_LIBFT) $(I_HEADER) $< -o $@


$(MLX):
	@printf "\n$(CYN)Generating MiniLibX...$(WTH)\n"
	@make -C $(MLX_PATH)
	@printf "$(GRN)MiniLibX created!$(WTH)\n\n"

$(LIBFT):
	@printf "\n$(GRN)Generating Libft...$(WTH)\n"
	@make -C $(LFT_PATH)
	@printf "$(GRN)Libft created!$(WTH)\n\n"

$(GFX):
	@printf "\n$(GRN)Generating Libgfx...$(WTH)\n"
	@make -C $(GFX_PATH)
	@printf "$(GRN)Libgfx created!$(WTH)\n\n"

bonus: all

re: fclean all

rebonus: fclean bonus

leaks:
	$(LEAKS) $(LF)
	@printf "$(GRN)Leaks log ready! Check valgrind-out.txt $(WTH)\n\n"

cleanleaks:
	$(RM) $(LEAKS_FILE)
	@printf "$(GRN)Leaks log file deleted.$(WTH)\n\n"

clean:
	@printf "\n$(YE)Cleaning all object files from libft...$(WTH)\n"
	@make clean -C $(LFT_PATH)
	@printf "$(GRN)Libft objects removed!$(WTH)\n\n"
	$(RM) -rf $(OBJ) $(BONUS_OBJ) $(OBJSDIR)
	# objs/

fclean: clean
	@printf "\n$(YE)Cleaning all additional objects and libraries...$(WTH)\n"
	$(RM) -rf $(NAME) $(BONUS_OBJ) objs/
	@make fclean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH)
	@printf "$(GRN)All libraries removed!$(WTH)\n\n"
	make cleanleaks

install:
	sudo apt-get install gcc make xorg libxext-dev libbsd-dev -y
	@printf "$(GRN)All dependencies ready!$(WTH)\n\n"

.PHONY: clean fclean re rebonus all bonus build

show:
	@echo "$(YLW)[ALL PATHS  ]$(WTH) *invoked with > make show*"
	@echo ""
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU) $(LFT_PATH)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIBFT FILE = ]$(WTH) $(LIBFT) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIB DIR  = ]$(WTH)$(BLU) $(MLX_PATH)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[LIBMLX FILE = ]$(WTH) $(MLX) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[MANDATORY SRC DIR 	= $(WTH) $(BLU)$(SRCDIR) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY SRC FILE	= $(WTH) $(notdir $(FILES)) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY TARGET DIR	= $(WTH) $(BLU)$(CURDIR) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY TARGET FILE	= $(WTH) $(notdir $(NAME)) $(YLW)]$(WTH)"
	@echo ""
	@echo "$(YLW)[GLOBAL OBJS DIR 	= $(WTH)$(BLU) $(OBJDIR)$(WTH) $(YLW)]$(WTH)"
	@echo "$(YLW)[MANDATORY OBJS FILE 	= $(WTH) $(notdir $(OBJ)) $(YLW)]$(WTH)"
	@echo ""
