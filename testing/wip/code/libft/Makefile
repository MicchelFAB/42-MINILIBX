# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 11:20:00 by antoda-s          #+#    #+#              #
#    Updated: 2023/07/15 15:36:19 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BACKUP MAKEFILE

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.
ARCH			= ar rcs
RM				= rm -f

SRCS		=	ft_free_str.c\
				ft_atoi.c \
				ft_atol.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_charjoin.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_issign.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_toupper.c \
				ft_tolower.c \
				\
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				\
				pf_all2s_1.c \
				pf_all2s_2.c \
				pf_fwp2f.c \
				pf_fwp2s.c \
				pf_tools.c \
				pf_type_n.c \
				pf_type_scp.c \
				pf_printf.c \
				\
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				\
				ft_split.c  \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				\
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstsize.c \
				ft_lstadd_back.c \
				\
				get_next_line.c

OBJS			= $(SRCS:%.c=%.o)

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
	@echo "Library : Compile Libft.a"
	@$(ARCH) $(NAME) $(OBJS)
	@echo "Library : Compile Libft.a done!"

$(OBJS):		$(SRCS)
	@echo "Library : Compile *.c -> *.o without linking"
	@$(CC) $(CFLAGS) -c $(SRCS)
	@echo "Library : Compile *.c -> *.o without linking done!"

clean:
	@echo "Library : Cleaning Libs Objs..."
	@$(RM) $(OBJS) libft.so
	@echo "Library : Cleaning Libs Objs done!"

fclean:			clean
	@echo "Library : Cleaning Libft.a"
	@$(RM) $(NAME)
	@echo "Library : Cleaning Libft.a done!"

re:	fclean $(NAME)

.PHONY:			all clean fclean re so

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

# .SILENT: