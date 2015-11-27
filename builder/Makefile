##
## Makefile for  in /home/penava_b/perso/C/C_exeptions_lib/examples/builder
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Fri Nov 27 13:20:18 2015 penava_b
## Last update Fri Nov 27 17:45:56 2015 penava_b
##

CC =		gcc

RM =		rm -f

NAME =		libUnitTest.so

SRC =		main.c

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
