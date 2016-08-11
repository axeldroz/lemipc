/*
** ia3.c for ia3 in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun Mar 27 22:05:06 2016 drozdz_b
** Last update Sun Mar 27 23:35:04 2016 drozdz_b
*/

#include "map.h"

struct s_case		*get_empty_array(struct s_case **map, int *len)
{
  struct s_case		*empty;
  int			a;
  int			i;
  int			j;

  a = i = j = 0;
  if (NULL == (empty = malloc(sizeof(struct s_case) * W_MAP * H_MAP)))
    return (NULL);
  while (j < H_MAP)
    {
      while (i < W_MAP)
	{
	  if (map[i][j].nteam == EMPTY_CHAR)
	    empty[a++] = create_case(i, j, map[i][j].nteam);
	  ++i;
	}
      i = 0;
      ++j;
    }
  *len = a;
  i = 0;
  while (i < *len)
      ++i;
  return (empty);
}

struct s_case		get_closest_empty(struct s_case **map, t_player player,
					  int *len)
{
  struct s_case		*empty;
  struct s_case		e;
  int			i;
  int			max;
  int			d;

  e.x = -1;
  e.y = -1;
  e.nteam = -1;
  max = -1;
  empty = get_empty_array(map, len);
  i = 0;
  while (i < *len)
    {
      d = get_distance(player, empty[i]);
      if (max < d)
	{
	  max = d;
	  e = empty[i];
	}
      ++i;
    }
  free (empty);
  return (e);
}
