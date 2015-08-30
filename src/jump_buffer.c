/*
** jump_buffer.c for  in /home/penava_b/perso/tricks/exceptions/src
** 
** Made by bastien penavayre
** Login   <penava_b@epitech.net>
** 
** Started on  Sun Aug 30 05:20:57 2015 bastien penavayre
** Last update Sun Aug 30 05:24:26 2015 bastien penavayre
*/

#include	"exceptions.h"

static jmp_buf	env;

jmp_buf		*__get_jump()
{
  return &env;
}
