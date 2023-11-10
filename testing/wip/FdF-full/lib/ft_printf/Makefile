# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 16:48:38 by ailopez-          #+#    #+#              #
#    Updated: 2022/06/03 13:50:22 by aitoraudi        ###   ########.fr        #
#    Updated: 2022/05/24 00:35:24 by aitorlope        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#Variables

NAME		= libftprintf.a
INCLUDE		= inc
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -I
RM			= rm -f
AR			= ar rcs

# Colors

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m
DEF_COLOR 	= \033[0;39m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	ft_printf_aux ft_printf_aux2 ft_printf_itoa ft_printf_du ft_printf_sc ft_printf_xp ft_printf_xp2 ft_printf 


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:	
	@Make makelibs
	@echo "\n🎯 $(YELLOW)Starting $(WHITE)[$(NAME)]$(YELLOW) compilation..$(DEF_COLOR)"	
	@Make $(NAME)
	@echo "\n🔰 $(GREEN)$(NAME) done!\n$(DEF_COLOR)"

makelibs:	
			@$(MAKE) -s -C $(LIBFT)
			
-include 	${DEPS}
$(NAME):	$(OBJ) ${LIBFT}/libft.a $(INCLUDE)/ft_printf.h
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "\n🔗$(CYAN) $(AR) $(NAME) $(OBJ)$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@${CC} ${CFLAGS} -I./ -c $< -o $@
			@printf "\r                                                                                                "
			@printf "\r🔧 $(GRAY)${CC} ${CFLAGS} -I./ -c $< -o $@$(DEF_COLOR)"

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(MAGENTA)🚽 Cleaned $(NAME)$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@make fclean -C $(LIBFT)	
			@echo "$(MAGENTA)🚽 Fcleaned $(NAME)$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm

