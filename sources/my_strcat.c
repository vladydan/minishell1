/*
** my_strcat.c for my_strcat in /home/danilo_d/rendu/Piscine_C_J07
** 
** Made by dimitri danilov
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Oct  7 21:26:28 2014 dimitri danilov
** Last update Wed Jan 14 19:48:54 2015 Danilov Dimitri
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      j++;
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
