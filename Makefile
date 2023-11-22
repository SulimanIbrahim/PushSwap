# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 16:59:41 by suibrahi          #+#    #+#              #
#    Updated: 2023/11/21 23:31:00 by suibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= operations.c\
		parsing.c\
		push_swap_utils.c\
		algorithm.c		\
		main.c
	

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3

OBJS	= $(SRCS:.c=.o)

NAME	= push_swap

RM		= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -C ./Libft-42
	$(CC) $(CFLAGS) $(OBJS) ./Libft-42/libft.a -o push_swap

clean :
	$(RM) $(OBJS)
	@make clean -C ./Libft-42

fclean : clean
	$(RM) $(NAME)
	@make fclean -C ./Libft-42

re : fclean all