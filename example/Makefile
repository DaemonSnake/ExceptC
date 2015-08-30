##
## Makefile for  in /home/penava_b/perso/tricks/exceptions/example
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Aug 30 04:49:10 2015 bastien penavayre
## Last update Sun Aug 30 08:53:49 2015 bastien penavayre
##

CC =		gcc

RM =		rm -f

NAME =		test

SRC =		main.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -I ../inc/

LDFLAGS =	$(COMMON) -L .. -lExcept -Wl,-rpath=../

all: 		$(NAME)

$(NAME): 	$(OBJ)
		make -C ..
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
