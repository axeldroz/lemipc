/*
** player2.c for player2 in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun Mar 27 20:51:13 2016 drozdz_b
** Last update Sun Mar 27 23:40:03 2016 drozdz_b
*/

#include "my.h"
#include "map.h"

int		zbir_action(struct s_case **map, t_map_info *map_info,
			    t_player *player)
{
  struct s_case	dir;
  struct s_case enemy;
  char		*receive;
  int		x;
  int		y;

  receive = receive_msg(player);
  x = (int)receive[0];
  y = (int)receive[1];
  if (x < 0 || y < 0)
    {
      if (x == player->x && y == player->y)
	{
	  player->attribute = 1;
	  return (1);
	}
      return (0);
    }
  enemy.x = x;
  enemy.y = y;
  dir = get_dir(&enemy, player);
  player_move(map, *map_info, player, dir);
  free(receive);
  return (0);
}

int		cowar_action(struct s_case **map, t_map_info *map_info,
			     t_player *player)
{
  struct s_case	empty_case;
  int		nb;
  struct s_case dir;

  empty_case = get_closest_empty(map, *player, &nb);
  if (nb <= 0)
    return (-1);
  dir = get_dir(&empty_case, player);
  player_move(map, *map_info, player, dir);
  return (0);
}
