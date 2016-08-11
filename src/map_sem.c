/*
** map_sem.c for map_sem.c in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Tue Mar 22 16:20:53 2016 drozdz_b
** Last update Sun Mar 27 23:29:01 2016 drozdz_b
*/

#include "map.h"
#include "lemipc.h"

int	map_add_sem(t_map_info *info)
{
  int	i;
  int	j;

  i = j = 0;
  while (j < H_MAP)
    {
      while (i < W_MAP)
	{
	  info->sem_ids[i][j] = semget(info->key + i + j * H_MAP, 1, SHM_W);
	  if (info->sem_ids[i][j] == -1)
	    info->sem_ids[i][j] = semget(info->key + i + j * H_MAP, 1, IPC_CREAT
					 | SHM_W);
	  semctl(info->sem_ids[i][j], 0, SETVAL, 1);
	  ++i;
	}
      i = 0;
      ++j;
    }
  return (0);
}

void	map_del_sem(int sem_id[W_MAP][H_MAP], int width, int height)
{
  int	i;
  int	j;

  while (j < height)
    {
      while (i < width)
	{
	  semctl(sem_id[i][j], 0, IPC_RMID, 0);
	  ++i;
	}
      i = 0;
      ++j;
    }
}

void			map_fill_case(struct s_case **map, t_map_info info, t_player p)
{
    struct sembuf	decr;

    decr.sem_num = 0;
    decr.sem_flg = 0;
    decr.sem_op = -1;
    semop(info.sem_ids[p.x][p.y], &decr, 1);
    map[p.x][p.y].nteam = p.nteam;
}

void			map_clean_case(struct s_case **map, t_map_info info
				       , t_player p)
{
    struct sembuf	incr;

    incr.sem_num = 0;
    incr.sem_flg = 0;
    incr.sem_op = 1;
    map[p.x][p.y].nteam = EMPTY_CHAR;
    semop((info.sem_ids)[p.x][p.y], &incr, 1);
}
