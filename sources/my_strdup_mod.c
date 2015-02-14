/*
** my_strdup.c for strdup in /home/danilo_d/rendu/MUL_2014_wolf3d_big_screen
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Wed Dec 24 11:18:31 2014 Danilov Dimitri
** Last update Fri Jan 23 16:39:05 2015 Danilov Dimitri
*/

#include "my.h"

char	*my_strdup_mod(char *src, int lenght)
{
  int	i;
  char	*dest;

  i = 0;
  while (src[i] != '\0')
    i = i + 1;
  dest = xmalloc(i + lenght + 1);
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
