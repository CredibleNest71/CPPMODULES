# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mresch <mresch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 18:12:07 by mresch            #+#    #+#              #
#    Updated: 2024/10/31 13:07:59 by mresch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C		=	c++

NAME	=	fixed

FLAGS	=	-Wall -Wextra -Werror

SRC		=	main.cpp Fixed.cpp

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