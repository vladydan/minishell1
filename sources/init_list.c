/*
** init_list.c for init_list in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Jan 20 16:20:56 2015 Danilov Dimitri
** Last update Wed Jan 21 18:24:14 2015 Danilov Dimitri
*/

#include "my.h"

void	init_list(t_first_elem *begin, char **env)
{
  int	i;

  begin->first = NULL;
  begin->last = NULL;
  i = -1;
  while (env[++i] != NULL)
    ;
  while (i != 0)
    {
      add_to_first(begin, env[i - 1]);
      i--;
    }
}
