/*
** exceptions.c for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 23:26:37 2015 bastien penavayre
** Last update Sun Aug 30 09:33:16 2015 bastien penavayre
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"exceptions.h"

static t_list	*list = NULL;
static t_node	*last = NULL;

__attribute__((constructor))
static void    	init_list(void)
{
  list = __create_list(NULL);
}

__attribute__((destructor))
static void	end_list(void)
{
  delete_list(list);
}

static void	bad_call_exit(char *string)
{
  fprintf(stderr, "\x1b[31m[Error] %s, force exit!\x1b[0m\n", string);
  exit(EXIT_FAILURE);
}

void		__throw_func(char *type, size_t size, void *arg)
{
  jmp_buf	*pointer_save;

  __push_type(type, size, list, arg);
  if (((pointer_save = __get_jump()) == NULL) || !__pop_buff())
    bad_call_exit("Unhandled exception");
  longjmp(*pointer_save, -1);
}

char		__catch_func(char *type)
{
  t_node	*tmp;

  if (type == NULL || *type == '\0')
    return 42;
  tmp = list->start;
  while (tmp != NULL)
    {
      if (strcmp(type, tmp->type) == 0)
	return ((last = tmp) ? 42 : 42);
      tmp = tmp->next;
    }
  return 0;
}

char		__fill_exception(void *arg)
{
  if (last == NULL)
    return 0;
  pop_if_same(arg, last, list);
  last = NULL;
  return 42;
}
