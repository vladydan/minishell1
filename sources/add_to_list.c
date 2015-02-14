/*
** add_to_list.c for put_in_ist in /home/danilo_d/rendu/CPE_2014_Pushswap
** 
** Made by Danilov Dimitri
** Login   <danilo_d@epitech.net>
** 
** Started on  Tue Dec  9 15:42:09 2014 Danilov Dimitri
** Last update Sun Feb  1 15:47:58 2015 Danilov Dimitri
*/

#include "my.h"

void		add_to_first(t_first_elem *elem, char *env)
{
  t_list	*new_elem;

  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->env = my_strdup(env);
  new_elem->index = 1;
  new_elem->next = elem->first;
  new_elem->back = NULL;
  if (elem->first)
    elem->first->back = new_elem;
  else
    elem->last = new_elem;
  elem->first = new_elem;
}

void		add_to_end(t_first_elem *elem, char *env)
{
  t_list	*new_elem;

  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->env = my_strdup(env);
  new_elem->index = 1;
  new_elem->next = NULL;
  new_elem->back = elem->last;
  elem->last->next = new_elem;
  elem->last = new_elem;
}
