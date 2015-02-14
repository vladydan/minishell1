/*
** my_strlen.c for my_stlen in /home/danilo_d/rendu/PSU_2014_my_printf/lib/my
** 
** Made by Dimitri Danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Thu Nov 13 14:59:25 2014 Dimitri Danilov
** Last update Sun Jan 11 16:46:22 2015 Danilov Dimitri
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
