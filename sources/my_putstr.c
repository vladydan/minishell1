/*
** my_putstr.c for dimitri in /home/danilo_d/rendu/PSU_2014_my_printf
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Nov 15 14:31:27 2014 Dimitri Danilov
** Last update Sun Feb  1 19:38:25 2015 Danilov Dimitri
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    {
      write(2, "(null)\n", 7);
      return (0);
    }
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
