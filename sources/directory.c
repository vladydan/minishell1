/*
** directory.c for directoru in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Jan 20 11:42:07 2015 Danilov Dimitri
** Last update Sun Feb  1 19:15:24 2015 Danilov Dimitri
*/

#include "my.h"

char	*home_or_not_home(char *path, t_struct *tool, char **env,
			  t_first_elem *list)
{
  char	*home_path;

  (void)env;
  (void)list;
  if (path[0] == '~')
    {
      home_path = xmalloc(my_strlen(path) + 20);
      home_path[0] = 0;
      my_strcat(home_path, tool->prompt.home);
      my_strcat(home_path, &path[1]);
      return (home_path);
    }
  else if (path[0] == '-' && path[1] == '\0')
    return (tool->command.old_pwd);
  else
    return (path);
}

void	modify_path(char **arg, t_struct *tool, char *path)
{
  int   i;
  int   j;

  i = -1;
  j = my_strlen(tool->prompt.path);
  tool->command.old_pwd = my_strdup(tool->prompt.path);
  while (arg[++i] != NULL)
    {
      if (arg[i][0] == '.' && arg[i][1] == '\0');
      else if (arg[i][0] == '.' && arg[i][1] == '.')
	{
	  while (tool->prompt.path[--j] != '/')
	    ;
	  tool->prompt.path[j] = 0;
	}
      else
	{
	  tool->prompt.path = my_realloc(tool->prompt.path, my_strlen(path));
	  my_strcat(tool->prompt.path, arg[i]);
	}
    }
}

int	error_directory(char *path)
{
  if (path == NULL)
    {
      my_putstr("csh: cd: OLDPWD not set\n");
      return (0);
    }
  my_putstr("cd :");
  my_putstr(path);
  my_putstr(" no such file or directory.\n");
  return (0);
}

int	change_path(t_struct *tool, char *path)
{
  if (path[0] == '/')
    {
      tool->command.old_pwd = my_strdup(tool->prompt.path);
      tool->prompt.path = my_realloc(tool->prompt.path, my_strlen(path));
      tool->prompt.path[0] = 0;
      my_strcat(tool->prompt.path, path);
      return (0);
    }
  return (1);
}

int     change_directory(t_struct *tool, char **env, char **argv,
			 t_first_elem *list)
{
  char	*path;
  char	**arg;

  if (argv[1] != NULL)
    path = argv[1];
  else
    path = my_strdup("\0");
  if (path[0] == 0)
    path[0] = '~';
  path = home_or_not_home(path, tool, env, list);
  if (chdir(path) == -1)
    {
      error_directory(path);
      return (0);
    }
  if (change_path(tool , path) == 0)
    return (0);
  arg = recup_argv(path, '/');
  modify_path(arg, tool, path);
  return (0);
}
