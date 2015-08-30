/*
** test.c for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 22:57:56 2015 bastien penavayre
** Last update Sun Aug 30 06:28:15 2015 bastien penavayre
*/

#include	<stdio.h>
#include	"exceptions.h"

int		division(int left, int right)
{
  if (right == 0)
    throw(char *, strdup("Division by zero Exception"));
  return left / right;
}

int		main()
{
  int		div = 0;

  try
    {
      division(5, 2);
      division(1, div);
      throw(double, 2.54);
    }
  catch(char *)
    {
      char *	msg;

      fillException(msg);
      printf("%s\n", msg);
      free(msg);
      throw(int, 5);
    }
  catch()
    printf("An exception occured\n");
  return 0;
}
