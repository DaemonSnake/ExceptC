//
// main.cpp for  in /home/penava_b/perso/tricks/exceptions/Compiler
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Mon Sep  7 00:21:19 2015 bastien penavayre
// Last update Mon Sep  7 00:59:34 2015 bastien penavayre
//

#include			<string>
#include			<iostream>
#include			<stack>

class				Compiler
{
  std::stack<std::string>      	linking;
  std::stack<std::string>	files;

public:
  Compiler(int ac, char **av) {
    for (int i = 0; i < ac; i++)
      (av[i][0] == '-' ? linking.push(av[i]) : files.push(av[i]));
  }
};

int		main(int ac, char **av)
{
  Compiler	comp(ac, av);

  return (0);
}
