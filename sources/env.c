/*
** env.c for env in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Jan 20 13:17:25 2015 Danilov Dimitri
** Last update Sun Feb  1 15:41:39 2015 Danilov Dimitri
*/

#include "my.h"

int	check_param(t_struct *tool, char *name, char *data)
{
  int	i;
  int	j;

  i = -1;
  while (tool->command.line[++i] != '\0')
    ;
  i++;
  j = -1;
  while (tool->command.line[i] != ' ' && tool->command.line[i] != '\0')
    {
      name[++j] = tool->command.line[i];
      i++;
    }
  name[++j] = 0;
  j = -1;
  while (tool->command.line[++i] != ' ' && tool->command.line[i] != '\0')
    data[++j] = tool->command.line[i];
  data[j + 1] = 0;
  return (0);
}

int     display_env(t_struct *tool , char **env , char **argv,
		    t_first_elem *list)
{
  (void)tool;
  (void)env;
  (void)argv;
  my_aff_list(list->first);
  return (0);
}

int     set_env(t_struct *tool , char **env , char **argv, t_first_elem *list)
{
  char	*var_env;
  char	*name;
  char	*data;

  name = xmalloc(my_strlen(&tool->command.line[6]) + 1);
  data = xmalloc(my_strlen(&tool->command.line[6])+ 1);
  check_param(tool, name, data);
  if (check_if_exist(list->last, name, data) != 1)
    {
      var_env = xmalloc(my_strlen(name) + my_strlen(data) + 2);
      var_env[0] = 0;
      my_strcat(var_env, name);
      my_strcat(var_env, "=");
      my_strcat(var_env, data);
      add_to_end(list, var_env);
    }
  (void)env;
  (void)argv;
  return (0);
}

int	unset_env(t_struct *tool, char **env, char **argv, t_first_elem *list)
{
  int	i;
  char	*var;

  (void)env;
  (void)argv;
  i = 0;
  while (tool->command.line[i] != '\0')
    i++;
  var = my_strdup(&tool->command.line[++i]);
  find_pos(list->last, var);
  return (0);
}
