/*
** test.c for  in /home/penava_b/perso/tricks/exceptions/Compiler
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Mon Sep  7 01:11:36 2015 bastien penavayre
** Last update Mon Sep  7 01:19:59 2015 bastien penavayre
*/

#include <stdio.h>
#include <stdlib.h>

static void	*save;

void		*push(size_t s)
{
  save = malloc(s);
  return save;
}

void		*getLast(int lol, ...)
{
(void)lol;
return save;
}

void		func(char *str)
{
  printf("%p\n", str);
printf("%d\n", *(char *)str);
}

int		main()
{
func(getLast(0, (*((char *)push(sizeof(char))) = 2L)));
return (0);
}
