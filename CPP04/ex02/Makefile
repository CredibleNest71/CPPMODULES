# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mresch <mresch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 18:12:07 by mresch            #+#    #+#              #
#    Updated: 2024/11/06 13:23:01 by mresch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C		=	c++

NAME	=	animals_with_brains2

FLAGS	=	-Wall -Wextra -Werror -g -std=c++98

SRC		=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS	=	$(SRC:.cpp=.o)

$(NAME): $(OBJS)
		$(C) $(FLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
		$(C) $(FLAGS) -c $< -o $@
	
all:	$(NAME)

clean:
		@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)

re:		fclean all

.PHONY: all clean re fclean