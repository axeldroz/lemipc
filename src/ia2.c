/*
** ia2.c for ia2 in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu Mar 24 19:36:28 2016 drozdz_b
** Last update Sun Mar 27 23:38:29 2016 drozdz_b
*/

#include "map.h"

int	nb_player_of_team(int *others, int nteam)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (i < 9)
    {
      if (nteam == others[i])
	++n;
      ++i;
    }
  return (n);
}

int	*get_player_around(struct s_case **map, int x, int y)
{
  int	*tab;

  tab = malloc(sizeof(int) * 9);
  if (tab == NULL)
    return (NULL);
  tab[0] = (x > 0 && y > 0) ? map[x - 1][y - 1].nteam : EMPTY_CHAR;
  tab[1] = (x > 0) ? map[x - 1][y].nteam : EMPTY_CHAR;
  tab[2] = (x > 0 && y < H_MAP - 1) ? map[x - 1][y + 1].nteam : EMPTY_CHAR;
  tab[3] = (y > 0) ? map[x][y - 1].nteam : EMPTY_CHAR;
  tab[4] = (y < H_MAP - 1) ? map[x][y + 1].nteam : EMPTY_CHAR;
  tab[5] = (x < W_MAP - 1 && y > 0) ? map[x + 1][y - 1].nteam : EMPTY_CHAR;
  tab[6] = (x < W_MAP - 1) ? map[x + 1][y].nteam : EMPTY_CHAR;
  tab[7] = (x < W_MAP - 1 && y < H_MAP - 1) ? map[x + 1][y + 1].nteam
      : EMPTY_CHAR;
  tab[8] = '\0';
  return (tab);
}

int	is_dead(struct s_case **map, t_player *player)
{
  int	*others;
  int	i;

  others = get_player_around(map, player->x, player->y);
  i = 0;
  while (i < 9)
    {
      if (others[i] > 0 && nb_player_of_team(others, others[i]) >= 2)
	{
	  free (others);
	  return (1);
	}
      ++i;
    }
  free (others);
  return (0);
}

struct s_case		*get_friend_array(struct s_case **map, int nteam, int *len)
{
  struct s_case		*friends;
  int			a;
  int			i;
  int			j;

  a = i = j = 0;
  friends = malloc(sizeof(struct s_case) * W_MAP * H_MAP);
  if (friends == NULL)
   return (NULL);
  while (j < H_MAP)
    {
      while (i < W_MAP)
	{
	  if (map[i][j].nteam != EMPTY_CHAR && map[i][j].nteam == nteam)
	    friends[a++] = create_case(i, j, map[i][j].nteam);
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
  return (friends);
}

struct s_case		get_closest_friend(struct s_case **map, t_player player, int *len)
{
  struct s_case		*friends;
  struct s_case		e;
  int			i;
  int			max;
  int			d;

  e.x = 0;
  e.y = 0;
  e.nteam = 0;
  max = -1;
  friends = get_friend_array(map, player.nteam, len);
  i = 0;
  while (i < *len)
    {
      d = get_distance(player, friends[i]);
      if (max < d)
	{
	  max = d;
	  e = friends[i];
	}
      ++i;
    }
  free (friends);
  return (e);
}
