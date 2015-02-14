/*
** my_list_size.c for my_list_size in /home/danilo_d/rendu/Piscine_C_J12/ex_02
** 
** Made by dimitri danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Oct 21 17:18:12 2014 dimitri danilov
** Last update Sun Feb  1 19:41:34 2015 Danilov Dimitri
*/

#include "my.h"

int	my_aff_list(t_list *begin)
{
  while (begin != NULL)
    {
      if (begin->index != 0)
	{
	  my_putstr(begin->env);
	  my_putchar('\n');
	}
      begin = begin->next;
    }
  return (0);
}

int	check_if_exist(t_list *begin, char *name, char *data)
{
  int	ret;

  ret = 1;
  while (begin != NULL && (ret = my_strncmp(name, begin->env, my_strlen(name)
					    - 1) != 0) && begin->back != NULL)
    {
      begin = begin->back;
    }
  if (ret == 0)
    {
      free(begin->env);
      begin->env = xmalloc(my_strlen(name) + my_strlen(data) + 2);
      begin->env[0] = 0;
      begin->index = 1;
      my_strcat(begin->env, name);
      my_strcat(begin->env, "=");
      my_strcat(begin->env, data);
      return (1);
    }
  else
    return (0);
}

int	find_pos(t_list *begin, char *var)
{
  int	i;
  int	ret;

  i = 0;
  while ((ret = my_strncmp(var, begin->env, my_strlen(var) - 1))
	 != 0 && begin->back != NULL)
    {
      i++;
      begin = begin->back;
    }
  if (ret == 0)
    begin->index = 0;
  else
    my_putstr("This variable doesn't exist\n");
  return (i);
}
