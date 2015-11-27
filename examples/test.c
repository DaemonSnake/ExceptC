/*
** test.c for  in /home/penava_b/perso/C/C_exeptions_lib/examples
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 03:44:25 2015 penava_b
** Last update Fri Nov 27 04:08:06 2015 penava_b
*/

#include <stdlib.h>
#include <stdio.h>
#include "exception.h"

#define StringyFy(x) #x

__attribute__((constructor))
inline void    	TESTS()
{
}

void		write_new_code()
{
}

void		call()
{
}

int		main(int ac, char **av)
{
  int		i;

  for (i = 1; i < ac; i++)
    call(av[i]);
}
