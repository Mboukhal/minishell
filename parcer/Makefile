# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 19:25:13 by mboukhal          #+#    #+#              #
#    Updated: 2022/08/16 14:30:44 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= all

NAME				= minishell_parcer.a
SRC 				= src/
CFILES				= $(SRC)lexer.c $(SRC)token.c $(SRC)ft_realloc.c $(SRC)ft_strlcat.c $(SRC)ft_isalnum.c \
						$(SRC)parser.c $(SRC)parser1.c $(SRC)lexer1.c $(SRC)ft_putstr_fd.c $(SRC)arry_manip.c\
						$(SRC)ft_putchar_fd.c $(SRC)parser_start.c $(SRC)ft_putendl_fd.c $(SRC)ft_strncmp.c \
						$(SRC)heredoc.c $(SRC)back_slash.c $(SRC)err.c $(SRC)args_case.c $(SRC)redier.c \
						$(SRC)ft_getenv.c $(SRC)lexer_utils.c $(SRC)var_uti.c $(SRC)heredoc_utils.c

CFLAGS				= -Wall -Wextra -Werror
INCLUDE				= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib \
						-I/Users/$(USER)/.brew/opt/readline/lib #-std=gnu90
OBJS				= $(CFILES:.c=.o)

clean:
	@ $(RM) -rf $(OBJS)

fclean:
	@ $(RM) -rf $(OBJS); $(RM) -rf $(NAME)

re: fclean all

.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ $(AR) rc $(NAME) $(OBJS)

all: $(NAME) clean

.PHONY: re fclean all clean