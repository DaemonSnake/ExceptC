##
## Makefile for  in /home/penava_b/perso/tricks/exceptions/Compiler
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Tue Sep  8 16:03:29 2015 bastien penavayre
## Last update Tue Sep  8 17:03:53 2015 bastien penavayre
##

CXX =		g++

RM =		rm -f

NAME_COMP =	tryObj

NAME_LINK =	tryLink

SRC_COMP =	src/obj.cpp \
                src/Precompilator.cpp

SRC_LINK =	src/link.cpp \
		src/Precompilator.cpp

OBJ_COMP =	$(SRC_COMP:.cpp=.o)

OBJ_LINK =	$(SRC_LINK:.cpp=.o)

COMMON =       	-W -Wall -Wextra -Werror -std=c++11

CXXFLAGS =     	$(COMMON) -Iinc

LINKING =      	$(COMMON)

all:		$(NAME_COMP) $(NAME_LINK)

$(NAME_COMP):	$(OBJ_COMP)
		$(CXX) $(OBJ_COMP) -o $(NAME_COMP) $(LINKING)

$(NAME_LINK):	$(OBJ_LINK)
		$(CXX) $(OBJ_LINK) -o $(NAME_LINK) $(LINKING)

clean:
		$(RM) $(OBJ_LINK) $(OBJ_COMP)

fclean: 	clean
		$(RM) $(NAME_COMP) $(NAME_LINK)

re: 		fclean all
