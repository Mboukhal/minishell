# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:54:34 by mboukhal          #+#    #+#              #
#    Updated: 2022/08/16 17:06:14 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

NAME 			= minishell
FLAGS			= -Wall -Wextra -Werror
DIR_EXEC		= execution/
DIR_FUNC		= execution/functions/
DIR_PARC		= parcer/
SRC 			= $(DIR_FUNC)add_and_or_create_to_afile.c $(DIR_FUNC)cd.c \
					$(DIR_FUNC)export.c $(DIR_FUNC)unset.c \
					$(DIR_FUNC)add_env_var.c $(DIR_FUNC)echo.c \
					$(DIR_FUNC)ft_pwd.c $(DIR_FUNC)mod_env.c \$(DIR_FUNC)ft_splite.c \
					$(DIR_FUNC)ft_strjoin.c $(DIR_FUNC)ft_strdup.c \
					$(DIR_FUNC)ft_substr.c $(DIR_EXEC)ft_exec.c $(DIR_FUNC)others.c \
					$(DIR_EXEC)pipes.c $(DIR_FUNC)exit.c $(DIR_FUNC)err_exe.c \
					$(DIR_FUNC)ft_getenv.c $(DIR_EXEC)utils_exec.c \
					main.c utils.c

LIB 			= $(DIR_PARC)minishell_parcer.a 
					
INCLUDE 		= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
OBJS			= $(CFILES:.c=.o)

all : $(NAME)

.c.o:
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ make -C $(DIR_PARC)
	@ $(CC) $(FLAGS) $(INCLUDE) $(OBJS) $(LIB) $(SRC) -o $(NAME) # -fsanitize=address
	@ make fclean -C $(DIR_PARC)

bonus: all

fclean: clean
	@ make fclean -C $(DIR_PARC)
	@ $(RM) -f $(NAME) 

clean:
	@ make clean -C $(DIR_PARC)
	@ $(RM) -f $(OBJS) $(LIB)

re: fclean all
	@ make re -C $(DIR_PARC)

.PHONY: fclean clean re all