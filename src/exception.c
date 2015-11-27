/*
** test.c for  in /home/penava_b/perso/test
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Thu Nov 26 18:54:58 2015 penava_b
** Last update Fri Nov 27 03:33:50 2015 penava_b
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>

typedef struct 	s_info_node
{
  const char	*file;
  const char	*func;
  int		line;
  struct s_info_node *next;
}		info_node;

typedef struct s_node List;

struct	       	s_node
{
  int	       	status;
  jmp_buf      	buff;
  const char   	*type;
  char  	*obj;
  void		(*deletor)(void *);
  info_node    	*origin;
  List	       	*next;
};

List		*list = NULL;

static void	clean_node(List *node)
{
  info_node	*save;
  info_node	*save2;

  save = node->origin;
  node->origin = NULL;
  while (save != NULL)
    {
      save2 = save;
      save = save->next;
      free(save2);
    }
  if (node->obj != NULL && node->deletor != NULL)
    node->deletor(node->obj);
  node->obj = NULL;
}

static void    	pop_current()
{
  List		*tmp;

  tmp = list;
  list = list->next;
  clean_node(tmp);
  free(tmp);
}

static void    	trace_back(const char *file, const char *func, int line)
{
  info_node	*tmp;

  fprintf(stderr, "!!! TRACE_BACK !!!\n");
  fprintf(stderr, "\tDispatched in file '%s' in function '%s' at line '%d'\n",
	  file, func, line);
  for (tmp = list->origin; tmp != NULL; tmp = tmp->next)
    if (tmp->next != NULL)
      fprintf(stderr, "\tDispatched in file '%s' in function '%s' at line '%d'\n",
	      tmp->file, tmp->func, tmp->line);
    else
      fprintf(stderr, "\tComming from file '%s' in function '%s' at line '%d'\n",
	      tmp->file, tmp->func, tmp->line);
  fprintf(stderr, "Uncaught exception: (%s): '%s'\n", list->type, list->obj);
  pop_current();
  exit(42);
}

void		__throw_func(const char *type, char *obj, const char *file, const char *func, int line, void (*deletor)(void *))
{
  info_node	*node;

  while (list != NULL && list->status == 3)
    {
      if (list->obj == obj)
	{
	  if (list->deletor != deletor)
	    deletor = list->deletor;
	  list->obj = NULL;
	}
      pop_current();
    }
  if (list == NULL)
    {
      fprintf(stderr, "Uncaught exception: in file '%s' in func '%s' at line '%d'\n\
(%s): '%s'\n", file, func, line, type, obj);
      deletor(obj);
      exit(42);
    }
  list->status = 2;
  list->type = type;
  list->obj = obj;
  list->deletor = deletor;
  if ((node = malloc(sizeof(info_node))) != NULL)
    {
      node->file = file;
      node->func = func;
      node->line = line;
      node->next = list->origin;
      list->origin = node;
    }
  longjmp(list->buff, -1);
}

int    		__dispatcher(const char *file, const char *func, int line)
{
  if (list->status == 0)
    {
      list->status = 1;
      return 42;
    }
  if (list->status == 2)
    {
      if (list->next == NULL)
	trace_back(file, func, line);
      clean_node(list->next);
      list->next->type = list->type;
      list->next->obj = list->obj;
      list->next->origin = list->origin;
      list->next->deletor = list->deletor;
      list->origin = NULL;
      list->obj = NULL;
      list->deletor = NULL;
      pop_current();
      __throw_func(list->type, list->obj, file, func, line, list->deletor);
    }
  pop_current();
  return 0;
}

int    		__initializer()
{
  List 		*tmp = malloc(sizeof(List));

  if (tmp == NULL)
    exit(fprintf(stderr, "Bad alloc in try!\n"));
  tmp->type = NULL;
  tmp->next = list;
  tmp->status = 0;
  tmp->type = NULL;
  tmp->obj = NULL;
  tmp->origin = NULL;
  list = tmp;
  return 42;
}

int    		__catch_func(const char *type)
{
  if (strcmp(type, list->type) == 0)
    {
      list->status = 3;
      return 42;
    }
  return 0;
}

void	       	*__except_get_front()
{
  return &list->buff;
}

void		__except_dont_do_shit(void *arg)
{
  (void)arg;
}
