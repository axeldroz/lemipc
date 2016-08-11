/*
** ia.c for ia in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Mar 23 21:56:49 2016 drozdz_b
** Last update Sun Mar 27 23:39:09 2016 drozdz_b
*/

#include "map.h"

struct s_case		create_case(int x, int y, int nteam)
{
  struct s_case		e;

  e.x = x;
  e.y = y;
  e.nteam = nteam;
  return (e);
}

struct s_case		*get_enemy_array(struct s_case **map, int nteam, int *len)
{
  struct s_case		*enemies;
  int			a;
  int			i;
  int			j;

  a = i = j = 0;
  enemies = malloc(sizeof(struct s_case) * W_MAP * H_MAP);
  if (enemies == NULL)
   return (NULL);
  while (j < H_MAP)
    {
      while (i < W_MAP)
	{
	  if (map[i][j].nteam != EMPTY_CHAR && map[i][j].nteam != nteam)
	    enemies[a++] = create_case(i, j, map[i][j].nteam);
	  ++i;
	}
      i = 0;
      ++j;
    }
  *len = a;
  i = 0;
  while (i < *len)
    {
      ++i;
    }
  return (enemies);
}

int	get_distance(t_player p, struct s_case e)
{
  int	a;

  a = (e.x - p.x) * (e.x - p.x);
  a += (e.y - p.y) * (e.y - p.y);
  a = my_square_root(a);
  return (a);
}

struct s_case		get_closest(struct s_case **map, t_player player, int *len)
{
  struct s_case		*enemies;
  struct s_case		e;
  int			i;
  int			max;
  int			d;

  e.x = -1;
  e.y = -1;
  e.nteam = -1;
  max = -1;
  enemies = get_enemy_array(map, player.nteam, len);
  i = 0;
  while (i < *len)
    {
      d = get_distance(player, enemies[i]);
      if (max < d)
	{
	  max = d;
	  e = enemies[i];
	}
      ++i;
    }
  free (enemies);
  return (e);
}

struct s_case	get_dir(struct s_case *enemy, t_player *player)
{
  struct s_case	dir;
  int		a;
  int		b;

  a = enemy->x - player->x;
  b = enemy->y - player->y;
  if (ABS(b) < ABS(a))
    b = 0;
  else
    a = 0;
  if (a == 0)
    dir.x = 0;
  else
    dir.x = (a < 0) ? -1 : 1;
  if (b == 0)
    dir.y = 0;
  else
    dir.y = (b < 0) ? -1 : 1;
  return (dir);
}
