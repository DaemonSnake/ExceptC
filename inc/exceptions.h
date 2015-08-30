/*
** exceptions.h for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 23:22:46 2015 bastien penavayre
** Last update Sun Aug 30 07:56:18 2015 bastien penavayre
*/

#ifndef  _EXCEPTIONS_H_
# define  _EXCEPTIONS_H_

#include	<setjmp.h>
#include	"list.h"

jmp_buf		*__get_jump(void);
char		__catch_func(char *);
void		*__fill_exception(void *);
void		__throw_func(char *, size_t, void *);
char		__push_buff(void);
char		__pop_buff(void);

#define try if (__push_buff() && setjmp(*__get_jump()) == 0)
#define throw(type, var)						\
  __throw_func(#type, sizeof(type), (char *)TMP_POINTER(var))
#define catch(type) else if (__catch_func(#type))
#define fillException(var) __fill_exception(&var)
#define setException(var) (fillException(var), var)

#endif /*  _EXCEPTIONS_H_ */
