/*
** test.c for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 22:57:56 2015 bastien penavayre
** Last update Sun Aug 30 04:46:34 2015 bastien penavayre
*/

#include	<stdio.h>
#include	"exceptions.h"

int		division(int left, int right)
{
  if (right == 0)
    throw(char *, strdup("Tu ne peut pas diviser par 0!"));
  return left / right;
}

int		main()
{
  try
    {
      division(5, 2);
      division(1, 0);
    }
  catch(char *)
    {
      char	*var;

      fillException(var);
      printf("%s\n", var);
      free(var);
    }
  catch()
    {
      printf("An exception occured\n");
    }
  return 0;
}
