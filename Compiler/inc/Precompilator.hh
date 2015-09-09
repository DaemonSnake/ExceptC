//
// Precompilator.hh for  in /home/penava_b/perso/tricks/exceptions/Compiler
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Tue Sep  8 15:58:18 2015 bastien penavayre
// Last update Wed Sep  9 15:18:48 2015 bastien penavayre
//

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

class				Precompilator
{
  class				Pipe
  {
    int				_pipe[2];
    bool			_closed[2] = { false, false };

  public:
    Pipe();
    ~Pipe();
    int				read();
    int				write();
    void			closeAll();
    void			reset();
  };

  std::vector<const char *>	_linking;
  std::vector<const char *>	_files;
  const char  			*_comp;
  Pipe				_pipe;
  pid_t				_pid;

  void				call();
  static std::string   		to_obj(std::string &&);

public:
  Precompilator(int, const char **);
  ~Precompilator();
  template			<bool>
  void				launch();
};
