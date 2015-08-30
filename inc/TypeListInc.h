/*
** list.h for  in /home/penava_b/perso/tricks/TypeListC
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Thu Aug 27 07:06:44 2015 bastien penavayre
** Last update Sun Aug 30 08:47:44 2015 bastien penavayre
*/

#ifndef  TYPE_LIST_INC_H_
# define   TYPE_LIST_INC_H_

/*
** INCLUDES
*/

# include <stdlib.h>
# include <string.h>

/*
** DEFINES
*/

# define TMP_POINTER(x)				\
  ({						\
    typeof(x)	__TMP__ = x;			\
    &__TMP__;					\
  })

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

void		delete_list(t_list *);
char            pop_if_same(void *, t_node *, t_list *);

/*
** DEPRECATED, USE MACROS INSTEAD
 */

t_list		*__create_list(t_list *);
void		__push_type(char *, size_t, t_list *, char *);

#endif /*   TYPE_LIST_INC_H_ */
