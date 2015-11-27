##
## Makefile for  in /home/penava_b/perso/C/C_exeptions_lib
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Fri Nov 27 03:43:28 2015 penava_b
## Last update Fri Nov 27 03:43:40 2015 penava_b
##

CC =		gcc

RM =		rm -f

NAME =		libExcept.so

SRC =		src/exception.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -fPIC

LDFLAGS =	$(COMMON) -shared

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
