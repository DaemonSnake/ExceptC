##
## Makefile for  in /home/penava_b/perso/tricks/exceptions/Compiler
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Mon Sep  7 00:39:56 2015 bastien penavayre
## Last update Mon Sep  7 00:40:01 2015 bastien penavayre
##

CXX		= g++

RM =		rm -f

NAME =		tryGcc

SRC =		main.cpp

OBJ =		$(SRC:.cpp=.o)

COMMON =       	-W -Wall -Wextra -Werror -std=c++11

CXXFLAGS =     	$(COMMON)

LINKING =      	$(COMMON)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(OBJ) -o $(NAME) $(LINKING)
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
