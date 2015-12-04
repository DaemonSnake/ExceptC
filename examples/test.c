/*
** test.c for  in /home/penava_b/perso/C/C_exeptions_lib/examples
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 03:44:25 2015 penava_b
** Last update Tue Dec  1 21:29:30 2015 penava_b
*/

#include "unit_test_builder.h"

#define COMPILE_FLAGS -W -Wall -Wextra -Werror -I ../inc/ -Wl,-rpath=.. -L=.. -lExcept
#define INCLUDES #include <stdio.h> #include <stdlib.h> #include "exception.h" #include <string.h>

NEW_TESTS()
{
  PUSH_TEST("Standard", {
      try {
  	throw(char*, "Hello");
      }
      catch(char*, except) {
      	printf("Catched char*!\n");
      }
    });

  PUSH_TEST("Standard", {
      try {
  	try {
  	  throw(char*, "Hello");
  	}
  	catch(double*, except) {
  	  printf("Is a double*\n");
  	}
      }
      catch(char*, except) {
  	printf("Is char*\n");
      }
    });

  PUSH_TEST("NoTry", {
      throw(char*, "Hello");
    });

  PUSH_TEST("unchaught with try", {
      try {
  	throw(char*, "Hello");
      }
      catch(double*, except) {
      }
    });

  PUSH_TEST("uncaught in catch", {
      try {
  	throw (char*, "Hello");
      }
      catch(char*, except) {
  	try {
  	  throw(char*, "Loello");
  	}
  	catch(double*, except) {
  	}
      }
    });

  PUSH_TEST("deletor", {
      throw(double*, strdup("A string"), free);
    });
  
  PUSH_TEST("throw back received", {
      try {
      	try
	  throw(char*, strdup("LOl yolo"), free);
	catch(char*, except) {
	  printf("Exception of value : %s\n", except);
	  throw(char*, except);
	}
      }
      catch(char*, except)
      	printf("Received correctly '%s'\n", except);
    });
}
