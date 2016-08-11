/*
** game.c for game in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Mar 23 21:12:58 2016 drozdz_b
** Last update Sun Mar 27 23:26:15 2016 drozdz_b
*/

/*
** Fonctions qui lance et ferme le jeu
*/

#include "my.h"

void		go_display(struct s_case **map, t_map_info info)
{
  display_map(map, info.width, info.height);
  while (1)
    {
      CLEAR();
      display_map(map, info.width, info.height);
      usleep(100000);
    }
}

void		destruct_shm(struct s_case **map, t_map_info map_info, char *pwd)
{
  map = get_map(pwd, &map_info);
  shmctl(map_info.shm_id, IPC_RMID, NULL);
  map_del_sem(map_info.sem_ids, map_info.width, map_info.height);
  free_map(map, 4);
}

int			launch_game(int ac, char **av)
{
  struct s_case		**map;
  t_map_info		map_info;
  t_player		player;

  map = get_map(av[1], &map_info);
  if (map == NULL)
    {
      map = create_map(av[1], &map_info);
      go_display(map, map_info);

    }
  else
    {
      if (ac < 3)
	player.nteam = 1;
      else
	player.nteam = atoi(av[2]);
      get_msg_id(map_info.key, &player);
      launch_player(map, &map_info, &player);
      msgctl(player.msg_id, IPC_RMID, NULL);
    }
  free(map);
  return (0);
}
