##
## Makefile for  in /home/penava_b/perso/tricks/exceptions/example
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Aug 30 04:49:10 2015 bastien penavayre
## Last update Sun Aug 30 05:17:09 2015 bastien penavayre
##

CC =		gcc

RM =		rm -f

NAME =		test

SRC =		main.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -I ../inc/ -I ../TypeListC/inc/

LDFLAGS =	$(COMMON) -L .. -lExcept -Wl,-rpath=../

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
