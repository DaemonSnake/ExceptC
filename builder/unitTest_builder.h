/*
** unitTest_builder.h for  in /home/penava_b/perso/C/C_exeptions_lib/examples
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 13:15:41 2015 penava_b
** Last update Fri Nov 27 15:35:53 2015 penava_b
*/

#pragma once

#define Stringyfy(x) #x
#define Stringyfy2(x) Stringyfy(x)
#define MACRO(x) x
#define StringyfyX(...) MACRO(#__VA_ARGS__)
#define Stringyfy3(x) StringyfyX(x)
#define PAST(x, y) x ##y
#define PAST2(x, y) PAST(x, y)
#define PUSH_TEST(name, x) __unitTest_push_in_list(name, \
					   Stringyfy3(INCLUDES), "void __init__test__(int ac __attribute__((unused)), \
char **av __attribute__((unused))) "					\
					   #x				\
						      " int main(int ac, char **av) { __init__test__(ac, av); return 0; }", Stringyfy3(COMPILE_FLAGS))
#define NEW_TESTS() __attribute__((constructor)) static inline void PAST2(__unittest_TESTS_, __LINE__)()

void	__unitTest_push_in_list(const char *, const char *, const char *, const char *);
