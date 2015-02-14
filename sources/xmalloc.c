/*
** xmalloc.c for xmalloc in /home/danilo_d/rendu/MUL_2014_fdf/lib/my
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Dec  6 20:01:09 2014 Danilov Dimitri
** Last update Sun Feb  1 15:05:18 2015 Danilov Dimitri
*/

#include "my.h"

void	*xmalloc(int nbr)
{
  void	*ret;

  ret = malloc(nbr);
  if (ret == NULL)
    exit(1);
  return (ret);
}
