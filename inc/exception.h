/*
** exception.h for  in /home/penava_b/perso/test
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 02:11:31 2015 penava_b
** Last update Fri Nov 27 18:05:58 2015 penava_b
*/

#pragma once

#include <setjmp.h>

jmp_buf		*__except_get_front();
int	       	__initializer();
int	       	__dispatcher(const char *, const char *, int);
void	       	__throw_func(const char *, void *, const char *,
			     const char *, int, void (*)(void *));
int	       	__catch_func(const char *);
void		__except_dont_do_shit(void *);
void		*__except_get_data();

#define try							\
  if (__initializer())						\
    while (__dispatcher(__FILE__, __FUNCTION__, __LINE__))	\
      if (setjmp(*__except_get_front()) == 0)

#define catch(type)							\
  else if (__catch_func(#type))

#define throw(type, var, ...)					\
  __throw_func(#type, var, __FILE__, __FUNCTION__, __LINE__, (__except_dont_do_shit, ##__VA_ARGS__))

#define getExcept(type, name) type tmp = (type)__except_get_data()
