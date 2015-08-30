/*
** test.c for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 22:57:56 2015 bastien penavayre
** Last update Sun Aug 30 07:45:33 2015 bastien penavayre
*/

#include	<stdio.h>
#include	"exceptions.h"

int		division(int left, int right)
{
  if (right == 0)
    throw(char *, strdup("Division by zero Exception"));
  return left / right;
}

void		do_stuff()
{
  try
    {
      division(5, 2);
      division(1, 0);
    }
  catch(char *)
    {
      char *	msg;

      fillException(msg);
      printf("%s\n", msg);
      free(msg);
      throw(int, 5);
    }
}

int		main()
{
  try
    do_stuff();
  catch()
    printf("An exception occured\n");
  return 0;
}
