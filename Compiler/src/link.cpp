//
// link.cpp for  in /home/penava_b/perso/tricks/exceptions/Compiler/src
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Tue Sep  8 16:43:51 2015 bastien penavayre
// Last update Wed Sep  9 14:06:13 2015 bastien penavayre
//

#include	<Precompilator.hh>
#include	<stdlib.h>

int		main(int ac, const char **av)
{
  try		{
    Precompilator(ac, av).launch<false>();
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
