/*
** jump_buffer.c for  in /home/penava_b/perso/tricks/exceptions/src
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Aug 30 05:20:57 2015 bastien penavayre
** Last update Sun Aug 30 07:44:29 2015 bastien penavayre
*/

#include		"exceptions.h"

typedef struct s_env_node
t_env_node;

static			struct
{
  struct		s_env_node
  {
    jmp_buf		buff;
    struct s_env_node  	*next;
  }		        *start;
  t_env_node		*to_del;
}			list = { NULL, NULL };

__attribute__((destructor))
static void		__cleaner(void)
{
  if (list.to_del == NULL)
    return ;
  free(list.to_del);
  list.to_del = NULL;
}

jmp_buf			*__get_jump()
{
  __cleaner();
  return &list.start->buff;
}

char	  		__push_buff(void)
{
  t_env_node		*tmp;

  __cleaner();
  if ((tmp = malloc(sizeof(t_env_node))) == NULL)
    return 0;
  tmp->next = list.start;
  list.start = tmp;
  return 42;
}

char			__pop_buff(void)
{
  __cleaner();
  if (list.start == NULL)
    return 0;
  list.to_del = list.start;
  list.start = list.start->next;
  return 42;
}
