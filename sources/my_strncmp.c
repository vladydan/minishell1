/*
** my_strncmp.c for my_strncmp in /home/danilo_d/rendu/Piscine_C_J06
** 
** Made by dimitri danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Oct  7 09:45:30 2014 dimitri danilov
** Last update Sun Jan 11 17:45:53 2015 Danilov Dimitri
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	j;

  j = 0;
  while (j < n)
    {
      if (s1[j] != s2[j])
	{
	  return (s1[j] - s2[j]);
	}
      j++;
    }
  return (0);
}
