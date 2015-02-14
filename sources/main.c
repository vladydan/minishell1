/*
** main.c for main in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Jan 14 17:45:02 2015 Danilov Dimitri
** Last update Sun Feb  1 15:39:44 2015 Danilov Dimitri
*/

#include "my.h"

int		main(int argc, char **argv, char **env)
{
  t_first_elem  *first;
  int		flag;

  flag = 0;
  if (argc != 1)
    {
      my_putstr("Usage : ./mysh\n");
      return (0);
    }
  (void)argv;
  first = xmalloc(sizeof(*first));
  if (env[0] == NULL)
    {
      flag = 1;
      my_putstr("No environnement found\n");
      first->first = NULL;
      first->last = NULL;
      add_to_first(first, "USER=NULL");
    }
  else
    init_list(first, env);
  signal(SIGINT, sig_signal);
  my_sh(env, first, flag);
  my_putchar('\n');
  return (0);
}
