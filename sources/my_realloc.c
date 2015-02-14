/*
** my_realloc.c for my_realloc.c in /home/danilo_d/rendu/PSU_2014_minishell1
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Jan 14 23:15:40 2015 Danilov Dimitri
** Last update Sun Feb  1 15:42:00 2015 Danilov Dimitri
*/

#include "my.h"

char	*my_realloc(char *str, int size)
{
  char	*new_str;
  int	i;

  i = -1;
  new_str = xmalloc(my_strlen(str) + size + 1);
  while (str[++i] != '\0')
    new_str[i] = str[i];
  new_str[i] = '/';
  new_str[++i] = '\0';
  str[0] = '\0';
  return (new_str);
}
