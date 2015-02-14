/*
** command.c for command in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Jan 20 12:22:33 2015 Danilov Dimitri
** Last update Sun Feb  1 15:30:20 2015 Danilov Dimitri
*/

#include "my.h"

int	execute(t_struct *tool, char **env,
		char **argv, t_first_elem *list)
{
  (void)list;
  tool->command.pid = fork();
  if (tool->command.pid == 0)
    {
      execve(tool->command.line, argv, env);
    }
  else
    wait(NULL);
  return (0);
}

int	im_your_father(t_struct *tool, char **env, char **argv)
{
  int	ret;

  ret = 0;
  if (tool->command.pid == 0)
    {
      ret = execve(tool->command.command, argv, env);
    }
  else
    wait(NULL);
  return (ret);
}

int	range_path(t_struct *tool, char **argv, char **env)
{
  int	i;
  int	ret;

  i  = - 1;
  while (tool->path[++i] != NULL)
    {
      tool->command.command = xmalloc(my_strlen(tool->path[i]) +
				      my_strlen(argv[0]) + 10);
      tool->command.command[0] = 0;
      my_strcat(tool->command.command, tool->path[i]);
      my_strcat(tool->command.command, "/");
      my_strcat(tool->command.command, argv[0]);
      ret = im_your_father(tool, env, argv);
      if (ret != -1)
        return (0);
    }
  my_putstr(argv[0]);
  my_putstr(":   command not found\n");
  if (tool->command.pid == 0)
    exit(1);
  return (0);
}

int	execute_path(t_struct *tool , char **env ,
		     char **argv, t_first_elem *list)
{
  int	i;

  if (env[0] == NULL)
    {
      my_putstr(argv[0]);
      my_putstr("    :command not found\n");
      return (0);
    }
  tool->command.pid = fork();
  (void)list;
  i = -1;
  if (my_strcmp("ls", argv[0]) == 0)
    {
      while (argv[++i] != NULL)
	;
      argv[i] = my_strdup("--color=auto");
      argv[++i] = NULL;
      i = -1;
    }
  range_path(tool, argv, env);
  return (0);
}

int	my_exit(t_struct *tool, char **env,
		char **argv, t_first_elem *list)
{
  (void)tool;
  (void)env;
  (void)argv;
  (void)list;
  exit(1);
  return (1);
}
