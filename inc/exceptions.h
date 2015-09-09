/*
** exceptions.h for  in /home/penava_b/perso/test
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Tue Jul 28 23:22:46 2015 bastien penavayre
** Last update Mon Sep  7 09:49:47 2015 bastien penavayre
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
void		__throw_func(const char *, const char *, int, ...);
void		__fail_catch(const char *, const char *, int);
void		**__create_empty(char *, size_t);

#define try if (__push_buff() && setjmp(*__get_jump()) == 0)
#define throw(type, var)						\
  __throw_func(__FILE__, __FUNCTION__, __LINE__ ,			\
	       (**(type**)__create_empty(#type, sizeof(type)) = (type)var))
#define catch(type) else if (__catch_func(#type))
#define setException(var) (__fill_exception(&var), var)
#define dispatchUncaught else				\
    __fail_catch(__FILE__, __FUNCTION__, __LINE__);

#endif /*  _EXCEPTIONS_H_ */
