##
## Makefile for  in /home/penava_b/perso/tricks/exceptions
## 
## Made by bastien penavayre
## Login   <penava_b@epitech.net>
## 
## Started on  Sun Aug 30 03:51:43 2015 bastien penavayre
## Last update Sun Aug 30 08:53:32 2015 bastien penavayre
##

CC =		gcc

RM =		rm -f

NAME =		libExcept.so

SRC =		src/exceptions.c \
		src/jump_buffer.c

OBJ =		$(SRC:.c=.o)

OBJS =		$(OBJ) TypeListC/libListTypeC.a

COMMON =	-W -Wall -Werror -Wextra

CFLAGS =	$(COMMON) -fPIC -I inc

LDFLAGS =	$(COMMON)

all: 		$(NAME)

$(NAME): 	$(OBJ)
		make -C TypeListC libListTypeC.a
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -shared
clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all
