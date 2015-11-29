##
## Makefile for  in /home/penava_b/perso/C/C_exeptions_lib/examples
## 
## Made by penava_b
## Login   <penava_b@epitech.net>
## 
## Started on  Fri Nov 27 03:47:06 2015 penava_b
## Last update Sun Nov 29 05:08:54 2015 penava_b
##

CC =		gcc

RM =		rm -f

NAME =		tests

SRC =		test.c

OBJ =		$(SRC:.c=.o)

COMMON =	-W -Wall -Werror -Wextra -g3

CFLAGS =	$(COMMON) -I ../CUnitTestBuilder/inc/

LDFLAGS =	$(COMMON) -L../CUnitTestBuilder/ -lUnitTest -Wl,-rpath=../CUnitTestBuilder/

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(MAKE) -C .. all
		$(MAKE) -C ../CUnitTestBuilder/ all
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(MAKE) -C .. clean
		$(MAKE) -C ../CUnitTestBuilder/ clean
		$(RM) $(OBJ)

fclean: 	clean
		$(MAKE) -C .. fclean
		$(MAKE) -C ../CUnitTestBuilder/ fclean
		$(RM) $(NAME)
		$(RM) _test_*
		$(RM) TestAll

re: 		fclean all
