/*
** my_strcmp.c for danilo_d in /home/danilo_d/rendu/rush
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Sat Jan  3 11:05:40 2015 Danilov Dimitri
** Last update Tue Jan 27 16:30:25 2015 Danilov Dimitri
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      if (s1[i] == '\0' && s2[i] == '\0')
	return (0);
      i = i + 1;
    }
  return (-1);
}
