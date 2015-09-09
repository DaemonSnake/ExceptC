//
// Pipe.cpp for  in /home/penava_b/perso/tricks/exceptions/Compiler/src
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Wed Sep  9 16:18:03 2015 bastien penavayre
// Last update Wed Sep  9 16:21:42 2015 bastien penavayre
//

#include <Precompilator.hh>
#include <unistd.h>

Precompilator::Pipe::Pipe() { pipe(_pipe); }

Precompilator::Pipe::~Pipe() {
  _closed[0] ? close(_pipe[0]) : 0;
  _closed[1] ? close(_pipe[1]) : 0;
}

template			<Precompilator::Pipe::action a>
void				Precompilator::Pipe::setFor()
{

  if (!_closed[static_cast<int>(!a)])
    {
      _closed[static_cast<int>(!a)] = true;
      close(_pipe[static_cast<int>(!a)]);
    }
  if (_closed[static_cast<int>(a)])
    {
      _closed[static_cast<int>(a)] = false;
      pipe(_pipe);
    }
}

int				Precompilator::Pipe::read()
{
  setFor<READ>();
  return _pipe[0];
}

int				Precompilator::Pipe::write()
{
  setFor<WRITE>();
  return _pipe[1];
}

void				Precompilator::Pipe::closeAll()
{
  if (!_closed[0])
    close(_pipe[0]);
  if (!_closed[1])
    close(_pipe[1]);
  _closed[0] = false;
  _closed[1] = false;
}

void				Precompilator::Pipe::reset()
{
  closeAll();
  pipe(_pipe);
}
