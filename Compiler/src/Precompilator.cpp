//
// Precompialator.cpp for  in /home/penava_b/perso/tricks/exceptions/Compiler/src
// 
// Made by bastien penavayre
// Login   <penava_b@epitech.net>
// 
// Started on  Tue Sep  8 15:59:28 2015 bastien penavayre
// Last update Wed Sep  9 16:13:58 2015 bastien penavayre
//

#include <Precompilator.hh>
#include <fstream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define LINK ".stdinasC.c"
#define LINK_C ".stdinasC.o"

Precompilator::Precompilator(int ac, const char **av) {
  bool			add(false);

  if (ac < 3)
    throw std::invalid_argument("./comp '[' list-of-link-rules ']' files...");
  _comp = av[1];
  _linking.push_back(av[1]);
  for (int i = 2; i < ac; i++)
    {
      if (std::string(av[i]) == "[")
	add = true;
      else if (std::string(av[i]) == "]")
	add = false;
      else
	(add ? _linking : _files).push_back(av[i]);
    }
  _linking.push_back(LINK);
  _linking.push_back((char *)0);
}

Precompilator::~Precompilator() {
  unlink(LINK);
}

void		       	Precompilator::call()
{
  symlink("/dev/stdin", LINK);
  if ((_pid = fork()) != 0)
    return ;
  dup2(_pipe.read(), 0);
  execvp(_comp, const_cast<char * const *>(&_linking[0]));
  throw std::exception();
}

std::string		Precompilator::to_obj(std::string &&other)
{
  size_t		s(other.find_last_of('.'));

  if (s <= 0)
    return other + ".o";
  return other.replace(s, other.length(), ".o");
}

void			Precompilator::threatFile(const char *file, int fd)
{
  std::ifstream    	stream(file);
  std::string		s;

  if (!stream.is_open())
    throw std::invalid_argument("Incorrect file : " + std::string(file));
  while (std::getline(stream, s))
    {
      write(fd, s.c_str(), s.length());
      write(fd, "\n", 1);
    }
}

template		<>
void			Precompilator::launch<false>()
{
  std::string	       	s;
  int		       	return_;
  int			fd;

  call();
  fd = _pipe.write();
  for (const char *file : _files)
    threatFile(file, fd);
  _pipe.closeAll();
  waitpid(_pid, &return_, 0);
}

template		<>
void			Precompilator::launch<true>()
{
  std::string	       	s;
  int		       	return_;
  int			fd;

  if (std::find(_linking.begin(), _linking.end(), "-c") == _linking.end())
    {
      _linking.pop_back();
      _linking.push_back("-c");
      _linking.push_back((char *)0);
    }
  for (const char *file : _files)
    {
      call();
      fd = _pipe.write();
      threatFile(file, fd);
      _pipe.reset();
      waitpid(_pid, &return_, 0);
      rename(LINK_C, to_obj(file).c_str());
    }
}

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
