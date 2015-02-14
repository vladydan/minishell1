/*
** my_putchar.c for my_putchar in /home/danilo_d/rendu/PSU_2014_my_printf
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Nov 15 14:36:19 2014 Dimitri Danilov
** Last update Sun Feb  1 18:12:14 2015 Danilov Dimitri
*/

#include "my.h"

int	my_putchar(int c)
{
  write(2, &c, 1);
  return (1);
}
