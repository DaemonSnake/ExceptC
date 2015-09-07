/*
** list.h for  in /home/penava_b/perso/tricks/TypeListC
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Thu Aug 27 07:06:44 2015 bastien penavayre
** Last update Mon Sep  7 02:14:35 2015 bastien penavayre
*/

#ifndef  LIST_H_
# define  LIST_H_

/*
** INCLUDES
*/

# include <stdlib.h>
# include <string.h>

/*
** DEFINES
*/

#define CREATE_LIST(...) __create_list((NULL, ##__VA_ARGS__))

/*
** TYPES
 */

typedef		struct s_node
t_node;

typedef		struct
{
  int		size;
  char		alloced;

  struct	s_node
  {
    char       	*data;
    char       	*type;
    size_t	size;
    t_node	*next;
  }		*start;
}		t_list;

/*
** PROTOTYPES
*/

char		contains_type(char *, t_list *);
char		pop_type(void *, char *, t_list *);
void		delete_list(t_list *);
char            pop_if_same(void *, t_node *, t_list *);

/*
** DEPRECATED, USE MACROS INSTEAD
 */

t_list		*__create_list(t_list *);
void		__push_type(char *, size_t, t_list *, char *);

#endif /*  LIST_H_ */
