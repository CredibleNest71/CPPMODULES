# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mresch <mresch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 18:12:07 by mresch            #+#    #+#              #
#    Updated: 2024/06/17 10:31:18 by mresch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C		=	clang++

NAME	=	horde

FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.cpp Zombie.cpp zombieHorde.cpp

OBJS	=	$(SRC:.cpp=.o)

$(NAME): $(OBJS)
		$(C) $(FLAGS) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
		@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean re fclean