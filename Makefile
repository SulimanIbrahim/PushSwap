# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suibrahi <suibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 16:59:41 by suibrahi          #+#    #+#              #
#    Updated: 2023/08/15 02:32:53 by suibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= operations.c\
		parsing.c\
		testing.c\
	

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)

NAME	= Pushswap.a

AR		= ar rc $(NAME) $(OBJS)

RM		= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)

	$(AR)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all