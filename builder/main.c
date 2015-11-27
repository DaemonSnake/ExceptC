/*
** main.c for  in /home/penava_b/perso/C/C_exeptions_lib/examples
** 
** Made by penava_b
** Login   <penava_b@epitech.net>
** 
** Started on  Fri Nov 27 13:12:25 2015 penava_b
** Last update Fri Nov 27 17:45:21 2015 penava_b
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct node node;

struct	       	node
{
  char		*file_name;
  char		*includes;
  char		*flags;
  char		*data;
  int		index;
  char		use_set;
  node		*next;
};

static node	*list;

char		*create_clean_macro(char *data)
{
  size_t       	new_size;
  size_t       	size;
  size_t       	i;
  size_t       	j;
  char		*res;

  size = strlen(data);
  new_size = 0;
  for (i = 0; i < size; i++)
    switch(data[i]) {
    case '{': case '}': case ';':
      new_size += 3;
      break;
    case ')': case '#':
      new_size += 2;
      break;
    default:
      new_size++;
      break;
    }
  if ((res = malloc(new_size + 1)) == NULL)
    return strdup(data);
  for ((i = 0, j = 0); i < size && j < new_size; (i++, j++))
    switch(data[i]) {
    case '{': case '}': case ';':
      res[j++] = '\n';
      res[j++] = data[i];
      res[j] = '\n';
      break;
    case ')':
      res[j] = data[i];
      if (i < size && data[i + 1] == ' ')
  	res[++j] = '\n';
      break;
    case '#':
      res[j++] = '\n';
      res[j] = data[i];
      break;
    default:
      res[j] = data[i];
      break;
    }
  res[j] = 0;
  return res;
}

void		__unitTest_push_in_list(char *file, char *includes, char *data, char *flags)
{
  node		*tmp;
  int		i;
  int		len;

  if ((tmp = malloc(sizeof(node))) == NULL)
    exit(printf("Bad alloc in push_in_list\n"));
  tmp->file_name = strdup(file);
  len = strlen(tmp->file_name);
  for (i = 0; i < len; i++)
    if (tmp->file_name[i] == ' ')
      tmp->file_name[i] = '-';
  tmp->data = create_clean_macro(data);
  tmp->use_set = 0;
  tmp->next = list;
  tmp->flags = flags;
  tmp->index = (list == NULL ? 0 : list->index + 1);
  len = strlen(includes);
  tmp->includes = create_clean_macro(includes);
  list = tmp;
}

__attribute__((destructor))
static inline void	__END_TESTS__()
{
  node		*tmp;
  while (list != NULL)
    {
      tmp = list;
      list = list->next;
      free(tmp->includes);
      free(tmp->file_name);
      free(tmp->data);
      free(tmp);
    }
}

static int     	call(int which)
{
  node		*tmp;
  int		fd;
  char		*tmpRes = NULL;
  char		*sourceName = NULL;

  if (which == -1)
    return (list == NULL ? -1 : list->index);
  for (tmp = list; tmp != NULL && tmp->index != which; tmp = tmp->next);
  if (tmp == NULL)
    return which;
  if (tmp->use_set != 0)
    return which;
  asprintf(&sourceName, "test_%s.c", tmp->file_name);
  if ((fd = creat(sourceName, S_IRUSR | S_IRGRP | S_IROTH)) == -1)
    return (fprintf(stderr, "Couldn't create test nb:%d\n", which), which);
  write(fd, tmp->includes, strlen(tmp->includes));
  write(fd, "\n", 1);
  write(fd, tmp->data, strlen(tmp->data));
  tmp->use_set = 42;
  asprintf(&tmpRes, "gcc %s %s -o test_%s_%d", sourceName, tmp->flags, tmp->file_name, which);
  if (system(tmpRes) != 0)
    fprintf(stderr, "\x1b[31mCouldn't compile test %s number %d\x1b[0m\n\n", tmp->file_name, which);
  else
    printf("\x1b[32mCompilation Ok for test %s number %d\x1b[0m\n\n", tmp->file_name, which);
  remove(sourceName);
  free(tmpRes);
  free(sourceName);
  return which;
}

#define TestAllString "#!/bin/bash\n\
\n\
for line in `ls | grep test_ | sort -t '_' -k 3n`;\n\
do\n\
    number=`echo $line | awk -F '_' '{print $NF}'`\n\
    name=`echo $line | awk -F '_' '{print $2}'`\n\
    ./$line;\n\
    if [ $? == 0 ]\n\
    then\n\
        echo \"$(tput setaf 2)Test $name n°$number worked$(tput sgr0)\"\n\
    else\n\
        echo \"$(tput setaf 1)Test $name n°$number failed$(tput sgr0)\"\n\
    fi\n\
    val=$(valgrind ./$line 2>&1 >/dev/null | grep \"total heap usage\")\n\
    echo \"$(tput setaf 1)$(echo $val | awk '{print $5}')$(tput sgr0) allocs and $(tput setaf 2)$(echo $val | awk '{print $7}')$(tput sgr0) frees\"\n\
    echo;\n\
done;"

int     	main(int ac, char **av)
{
  int		i;
  int		fd;

  if (ac < 2)
    {
      if ((ac = call(-1)) == -1)
	return fprintf(stderr, "No Unit test\n");
      for (i = 0; i <= ac; i++)
	call(i);
    }
  else
    for (i = 1; i < ac; i++)
      call(atoi(av[i]));
  remove("TestAll");
  if ((fd = creat("TestAll", 0755)) == -1)
    return fprintf(stderr, "Couldn't create TestAll\n");
  write(fd, TestAllString, 596);
}
