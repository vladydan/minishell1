/*
** recup_argv.c for recup_env in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Thu Jan 15 13:40:24 2015 Danilov Dimitri
** Last update Sun Feb  1 17:13:45 2015 Danilov Dimitri
*/

#include "my.h"

int	find_bad_arg(t_arg *arg)
{
  int	i;
  int	j;
  int	ok;

  i = -1;
  while (arg->argv[++i] != NULL)
    {
      j = -1;
      ok = 0;
      while (arg->argv[i][++j] != '\0')
	{
	  if (arg->argv[i][j] != ' ')
	    ok = 1;
	}
      if (ok != 1)
	{
	  arg->argv[i] = NULL;
	  return (0);
	}
    }
  return (0);
}

void	recup_argv_2(t_arg *arg, char *line, char c)
{
  while (arg->i < my_strlen(line))
    {
      while (line[arg->i] == c)
        arg->i++;
      arg->begin = arg->i;
      while (line[arg->i] != c && arg->i < my_strlen(line))
        arg->i++;
      arg->end = arg->i;
      arg->i = arg->begin;
      arg->argv[arg->nbr_param] = my_strndup(&line[arg->i],
					     arg->end - arg->begin);
      arg->nbr_param++;
      arg->i = arg->end;
      arg->i++;
    }
}

char	**recup_argv(char *line, char c)
{
  t_arg arg;

  arg.argv = xmalloc(1000);
  arg.nbr_param = 0;
  arg.i = 0;
  while (line[arg.i] == c)
    arg.i++;
  arg.begin = arg.i;
  while (line[arg.i] != c && arg.i < my_strlen(line))
    arg.i++;
  arg.end = arg.i;
  arg.argv[arg.nbr_param] = my_strndup(&line[arg.begin], arg.end - arg.begin);
  arg.nbr_param++;
  arg.i = arg.end;
  recup_argv_2(&arg, line, c);
  arg.argv[arg.nbr_param] = NULL;
  find_bad_arg(&arg);
  return (arg.argv);
}

void	recup_path(t_struct *tool, char **env)
{
  int	i;
  char	*path;

  i = -1;
  while ((my_strncmp(env[++i], "PATH=", 5)) != 0 && env[i + 1] != NULL)
    ;
  if (env[i + 1] == NULL)
    {
      my_putstr("Variable PATH missing\n");
      tool->path = xmalloc(10);
      tool->path[0] = my_strdup("/bin");
    }
  else
    {
      path = my_strdup(&env[i][5]);
      tool->path = recup_argv(path, ':');
    }
  i = -1;
  while (my_strncmp(env[++i], "HOME=", 5) != 0 && env[i + 1] != NULL);
  tool->prompt.home = my_strdup(&env[i][5]);
  if (env[i + 1] == NULL)
    {
      my_putstr("Variable HOME unset\n");
      tool->prompt.home = my_strdup("/home/");
    }
}
