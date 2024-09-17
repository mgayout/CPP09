# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 11:24:45 by mgayout           #+#    #+#              #
#    Updated: 2024/08/19 11:24:45 by mgayout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN
FLAG	= -Wall -Wextra -Werror -std=c++98
SRC		= main.cpp RPN.cpp

all: $(NAME)

$(NAME):
			c++ $(FLAG) $(SRC) -o $(NAME)

fclean:
			rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re