/*
** test.c for  in /home/penava_b/perso/C/C_exeptions_lib/examples
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 03:44:25 2015 penava_b
** Last update Fri Nov 27 17:32:14 2015 penava_b
*/

#include "unitTest_builder.h"

#define COMPILE_FLAGS -W -Wall -Wextra -Werror -I ../inc/ -Wl,-rpath=.. -L=.. -lExcept
#define INCLUDES #include <stdio.h> #include <stdlib.h> #include "exception.h"

NEW_TESTS()
{
  PUSH_TEST("Standard", {
      try {
  	throw(Object, "Hello");
      }
      catch(Object) {
      	printf("Catched Object!\n");
      }
    });

  PUSH_TEST("Standard", {
      try {
  	try {
  	  throw(Object, "Hello");
  	}
  	catch(String) {
  	  printf("Is a String\n");
  	}
      }
      catch(Object) {
  	printf("Is Object\n");
      }
    });

  PUSH_TEST("NoTry", {
      throw(Object, "Hello");
    });

  PUSH_TEST("unchaught with try", {
      try {
	throw(Object, "Hello");
      }
      catch(String) {
      }
    });

  PUSH_TEST("uncaught in catch", {
      try {
  	throw (Object, "Hello");
      }
      catch(Object) {
  	try {
  	  throw(Object, "Loello");
  	}
  	catch(String) {
  	}
      }
    });
}
