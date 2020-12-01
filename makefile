# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 18:19:02 by elahyani          #+#    #+#              #
#    Updated: 2020/12/01 14:38:37 by elahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell.a

SRCS =	execution.c \
		exp_cmd.c \
		debug.c \
		parsing/manag_list.c \
		parsing/parse_line.c \
		parsing/parse_list_line.c \
		parsing/parse_dollar.c \
		# cmds.c \
		# parsing/quotes.c \

SRC_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRCS:.c=.o)

OBJ_GNL = $(SRC_GNL:.c=.o)

LIBFT = ./libft/libft.a

MAIN = main.c

HEADER = minishell.h

LINKERFLAG = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ) $(MAIN) $(OBJ_LIB) $(OBJ_GNL) $(HEADER)
		@make -C ./libft
		@ar rcs $(NAME) $(OBJ) $(OBJ_LIB) $(OBJ_GNL)
		@gcc $(MAIN) $(NAME) $(LIBS) $(LIBFT) -o minishell
		@echo SUCCESS

%.o: %.c
		@gcc $(LINKERFLAG) $< -o $@

clean:
		@rm -f libft/libft.a
		@rm -f *.o
		@rm -f libft/*.o
		@rm -f get_next_line/*.o
		@rm -f parsing/*.o

fclean: clean
		@rm -f $(NAME)
		@rm -f minishell

re: fclean all