# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 19:26:31 by aribeiro          #+#    #+#              #
#    Updated: 2017/06/14 22:25:27 by aribeiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstractVM

SRC = 	BaseException.cpp \
		Factory.cpp \
		Lead.cpp \
		Lexer.cpp \
		main.cpp \
		Parser.cpp \
		tools.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Werror -Wextra

#variables for colors to highlight the make results
yellow	= \033[33;1m
blue	= \033[34;1m
magenta = \033[35;1m
green	= \033[32;1m
normal	= \033[0m

all : $(NAME)

$(NAME) : $(OBJ)
	clang++ -o $(NAME) $(OBJ)
	@printf "$(yellow)->./$(NAME) is created$(normal)\n"

%.o:%.cpp
	clang++ -c $< $(FLAGS)

clean :
	rm -rf $(OBJ)
	@printf "$(green)clean -> ok$(normal)\n\n"

fclean : clean
	rm -rf $(NAME)
	@printf "$(green)fclean -> ok"
	@printf "$(normal)\n\n"

re : fclean all

.PHONY : all clean fclean re
