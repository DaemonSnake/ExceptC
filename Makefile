##
## Makefile for  in /home/penava_b/perso/tricks/exceptions
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Aug 30 03:51:43 2015 bastien penavayre
## Last update Sun Aug 30 05:23:55 2015 bastien penavayre
##

CC =		gcc

RM =		rm -f

NAME =		libExcept.so

SRC =		src/exceptions.c \
		src/jump_buffer.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -I TypeListC/inc/ -fPIC -I inc

LDFLAGS =	$(COMMON) -Wl,--whole-archive TypeListC/libListTypeC.a -Wl,--no-whole-archive

all: 		$(NAME)

$(NAME): 	$(OBJ)
		make -C TypeListC libListTypeC.a
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -shared
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
