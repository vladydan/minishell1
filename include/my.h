/*
** my.h for header in /home/danilo_d/rendu/PSU_2014_my_select
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Thu Jan  8 23:18:31 2015 Danilov Dimitri
** Last update Sun Feb  1 17:38:58 2015 Danilov Dimitri
*/

#ifndef MY_H_
# define MY_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef	struct	s_arg
{
  int		i;
  int		begin;
  int		end;
  int		nbr_param;
  char		**argv;
}		t_arg;

typedef struct	s_prompt
{
  char		*path;
  char		*user_name;
  char		*home;
}		t_prompt;

typedef struct	s_list
{
  int		index;
  char		*env;
  struct s_list *next;
  struct s_list *back;
}		t_list;

typedef struct  s_first_elem
{
  t_list        *first;
  t_list        *last;
}               t_first_elem;

typedef struct  s_tool_comm
{
  char          line[10000];
  pid_t         pid;
  char          *command;
  char          *command2;
  char		*old_pwd;
}               t_tool_comm;

typedef struct	s_struct
{
  t_prompt	prompt;
  t_tool_comm	command;
  char		**path;
}		t_struct;

typedef struct	s_command
{
  char		*command;
  int		(*ptr)(t_struct *tool, char **env, 
		       char **argv, t_first_elem *list_env);
}		g_command;

char		*my_strdup(char *src);
int		my_putchar(int c);
int		my_putstr(char *str);
int		my_strlen(char *str);
char		*my_strcpy(char *dest, char *src);
void		*xmalloc(int nbr);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcat(char *dest, char *src);
int		my_sh(char **env, t_first_elem *list_env, int flag);
char		*my_realloc(char *str, int size);
char		*my_strdup(char *src);
char		*my_strndup(char *src, int size);
char		*my_strdup_mod(char *src, int lenght);
char		**recup_argv(char *line, char c);
int		execute_path(t_struct *tool , char **env ,
			     char **argv, t_first_elem *);
int		execute(t_struct *tool , char **env , 
			char **argv, t_first_elem *);
int		display_env(t_struct *tool , char **env , 
			    char **argv, t_first_elem *);
int		change_directory(t_struct *tool, char **env,
				 char **argv, t_first_elem *);
int		my_exit(t_struct *tool, char **env,
			char **argv, t_first_elem *);
int		set_env(t_struct *tool , char **env , 
			char **argv, t_first_elem *);
int		my_aff_list(t_list *begin);
void            add_to_first(t_first_elem *elem, char *env);
void		init_list(t_first_elem *begin, char **env);
void            add_to_end(t_first_elem *elem, char *env);
int		unset_env(t_struct *tool, char **env, char
			  **argv, t_first_elem *list);
int		alias_execute(t_struct *tool , char **env , 
			      char **argv, t_first_elem *list);
void		signal_quit(int sig);
int		check_if_exist(t_list *begin, char *name, char *data);
int		find_pos(t_list *begin, char *var);
void		print_prompt(t_struct *tool);
int		recup_prompt(char **env, t_struct *tool);
void		recup_path(t_struct *tool, char **env);
void		set_new_prompt(t_struct *tool);
void            sig_signal(int sig);

#endif  /* !MY_H_ */
