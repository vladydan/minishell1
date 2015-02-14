/*
** mysh.c for my_sh in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Jan 14 18:00:59 2015 Danilov Dimitri
** Last update Mon Feb  2 13:06:41 2015 Danilov Dimitri
*/

#include "my.h"

g_command  flag_choice[] =
  {
    {"./", &execute},
    {"env", &display_env},
    {"cd", &change_directory},
    {"exit", &my_exit},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {"\0", NULL},
    {"lol", &execute_path}
  };

void		sig_signal(int sig)
{
  (void)sig;
  my_putstr("\n> $ ");
}

int		something(char *line)
{
  int		i;

  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] != ' ')
	return (1);
      i++;
    }
  return (0);
}

int		choice(char **env, char **argv, t_struct *tool,
		       t_first_elem *list_env)
{
  int		i;

  i = -1;
  while ((my_strcmp("\0", flag_choice[++i].command)) != 0)
    {
      if (my_strcmp(tool->command.line, flag_choice[i].command) == 0)
        {
          flag_choice[i].ptr(tool, env, argv, list_env);
          return (0);
        }
    }
  i++;
  flag_choice[i].ptr(tool, env, argv, list_env);
  return (0);
}

void		init_env(char **env, t_struct *tool, int flag)
{
  if (flag == 0)
    {
      recup_prompt(env, tool);
      recup_path(tool, env);
    }
  else
    {
      tool->path = NULL;
      set_new_prompt(tool);
    }
  print_prompt(tool);
}

int		my_sh(char **env, t_first_elem *list_env, int flag)
{
  t_struct	*tool;
  char		**argv;
  int		i;
  int		ret;

  signal(SIGTSTP, sig_signal);
  tool = xmalloc(sizeof(*tool));
  init_env(env, tool, flag);
  argv = NULL;
  while ((ret = read(0, tool->command.line, 10000)) > 0)
    {
      tool->command.line[ret - 1] = 0;
      if (something(tool->command.line) == 1)
      	{
	  i = -1;
	  argv = recup_argv(tool->command.line, ' ');
	  while (tool->command.line[++i] != ' ' && tool->command.line[i] != '\0')
	    ;
	  tool->command.line[i] = 0;
	  choice(env, argv, tool, list_env);
	}
      print_prompt(tool);
      free(argv);
    }
  return (0);
}
