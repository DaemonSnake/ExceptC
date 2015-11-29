/*
** exception.h for  in /home/penava_b/perso/test
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 02:11:31 2015 penava_b
** Last update Sun Nov 29 07:22:07 2015 penava_b
*/

#pragma once

#include <setjmp.h>

jmp_buf		*__except_get_front();
int	       	__except_initializer();
int	       	__except_dispatcher(const char *, const char *, int);
void	       	__except_throw_func(const char *, void *, const char *,
				    const char *, int, void (*)(void *));
int	       	__except_catch_func(const char *);
void		__except_dont_do_shit(void *);
void		*__except_get_data();
void		*__except_get_non_last(void *, ...);
char		__except_get_catch_tool();


#define try								\
  for (__except_initializer(); __except_dispatcher(__FILE__, __FUNCTION__, __LINE__) ;)	\
    if (setjmp(*__except_get_front()) == 0)

#define catch(type, name)						\
  else if (__except_catch_func(#type))					\
    for (type name __attribute__((unused)) = __except_get_data(); __except_get_catch_tool(); )

#define throw(type, var, ...)						\
  __except_throw_func(#type, var, __FILE__, __FUNCTION__, __LINE__,	\
		      __except_get_non_last(__except_dont_do_shit, ##__VA_ARGS__, 0))
