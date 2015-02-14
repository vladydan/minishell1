/*
** prompt.c for prompt in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Jan 20 11:40:47 2015 Danilov Dimitri
** Last update Sun Feb  1 15:42:36 2015 Danilov Dimitri
*/

#include "my.h"

void		set_new_prompt(t_struct *tool)
{
  tool->path = xmalloc(2);
  tool->prompt.path = my_strdup("\0");
  tool->prompt.user_name = my_strdup(">");
  tool->path[0] = NULL;
  tool->path[1] = NULL;
  tool->prompt.home = my_strdup("/home/");
}

int		recup_prompt(char **env, t_struct *tool)
{
  int           i;

  i = -1;
  while (my_strncmp(env[++i], "PWD=", 4) != 0 && env[i + 1] != NULL);
  tool->prompt.path = my_strdup(&env[i][4]);
  if (env[i + 1] == NULL)
    {
      my_putstr("Variable PWD unset\n");
      tool->prompt.path = my_strdup("\0");
    }
  i = -1;
  while (my_strncmp(env[++i], "USER=", 5) != 0 && env[i + 1] != NULL);
  tool->prompt.user_name = my_strdup(&env[i][5]);
  if (env[i + 1] == NULL)
    {
      my_putstr("Variable USER unset\n");
      tool->prompt.user_name = my_strdup(">");
    }
  return (0);
}

void            print_prompt(t_struct *tool)
{
  my_putstr("\033[40;31m");
  my_putstr(tool->prompt.user_name);
  my_putstr("\033[40;32m");
  my_putstr(" ");
  my_putstr(tool->prompt.path);
  my_putstr(" $ ");
  my_putstr("\033[40;33m");
  my_putstr("\x1b[0m");
}
