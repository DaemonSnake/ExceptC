/*
** exceptions.h for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 23:22:46 2015 bastien penavayre
** Last update Mon Aug 31 08:40:25 2015 bastien penavayre
*/

#ifndef  _EXCEPTIONS_H_
# define  _EXCEPTIONS_H_

#include	<setjmp.h>
#include	"TypeListInc.h"

jmp_buf		*__get_jump(void);
char		__catch_func(char *);
char		__fill_exception(void *);
char		__push_buff(void);
char		__pop_buff(void);
void		__throw_func(char *, size_t, void *);

#define try if (__push_buff() && setjmp(*__get_jump()) == 0)
#define throw(type, var)						\
  __throw_func(#type, sizeof(type), (char *)TMP_POINTER(var))
#define catch(type, ...) else if (__catch_func(#type))
#define fillException(var) __fill_exception(&var)
#define setException(var) (fillException(var), var)

#endif /*  _EXCEPTIONS_H_ */
