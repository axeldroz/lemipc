/*
** player.c for player in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Mar 23 01:04:55 2016 drozdz_b
** Last update Sun Mar 27 23:40:47 2016 drozdz_b
*/

#include "my.h"

void		player_move(struct s_case **map, t_map_info info,
		    t_player *player, struct s_case mov)
{
  t_player	tmp;

  tmp = *player;
  player->x = player->x + mov.x;
  player->y = player->y + mov.y;
  if (player->x >= 0 && player->x < W_MAP
      && player->y >= 0 && player->y < H_MAP
      && map[player->x][player->y].nteam == EMPTY_CHAR)
    {
      map_fill_case(map, info, *player);
      map_clean_case(map, info, tmp);
    }
  else
    *player = tmp;
}

int	put_player(struct s_case **map, t_map_info info, t_player *player)
{
  int	x;
  int	y;

  x = rand() % W_MAP;
  y = rand() % H_MAP;
  if (map[x][y].nteam != EMPTY_CHAR)
    return (0);
  player->x = x;
  player->y = y;
  map_fill_case(map, info, *player);
  return (1);
}

int		player_assaut(struct s_case **map, t_map_info *map_info, t_player *player)
{
  struct s_case	enemy;
  struct s_case dir;
  int		len;
  char		str[2];

  enemy = get_closest(map, *player, &len);
  if (len <= 0)
    return (-1);
  dir = get_dir(&enemy, player);
  player_move(map, *map_info, player, dir);
  str[0] = enemy.x;
  str[1] = enemy.y;
  send_msg(player, str);
  return (0);
}

void			player_die(struct s_case **map, t_map_info *map_info, t_player *player)
{
  struct s_case 	chosen;
  int			len;
  char			msg[2];

  if (player->attribute == 1)
    {
      chosen = get_closest_friend(map, *player, &len);
      if (chosen.x < 0 || chosen.y < 0 || chosen.nteam < 0)
	{
	  msgctl(player->msg_id, IPC_RMID, NULL);
	}
      else
	{
	  msg[0] = - (chosen.x);
	  msg[1] = - (chosen.y);
	  send_msg(player, msg);
	}
    }
  map_clean_case(map, *map_info, *player);
}

void		launch_player(struct s_case **map, t_map_info *map_info, t_player *player)
{
  int		a;
  int		nb_friends;
  a = 1;
  while (!put_player(map, *map_info, player))
    usleep(SLEEP_TIME);
  get_friend_array(map, player->nteam, &nb_friends);
  if (nb_friends == 5 || nb_friends % 21 == 0)
    player->attribute = 2;
  while (!is_dead(map, player) && a)
    {
      if (player->attribute == 1)
	{
	  a += player_assaut(map, map_info, player);
	  usleep(SLEEP_TIME);
	}
      else if (player->attribute == 2)
	{
	  cowar_action(map, map_info, player);
	}
      else
	{
	  zbir_action(map, map_info, player);
	}
    }
  player_die(map, map_info, player);
}
