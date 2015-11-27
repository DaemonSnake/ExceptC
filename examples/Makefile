##
## Makefile for  in /home/penava_b/perso/C/C_exeptions_lib/examples
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Fri Nov 27 03:47:06 2015 penava_b
## Last update Fri Nov 27 03:51:42 2015 penava_b
##

CC =		gcc

RM =		rm -f

NAME =		tests

SRC =		test.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -I ../inc

LDFLAGS =	$(COMMON) -L../ -lExcept -Wl,-rpath=../

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(MAKE) -C .. all
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(MAKE) -C .. clean
		$(RM) $(OBJ)

fclean: 	clean
		$(MAKE) -C .. fclean
		$(RM) $(NAME)

re: 		fclean all
