/*
** map.c for map in /home/drozdz_b/Documents/Unix System/LemIPC/send_map
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sat Mar 19 23:11:33 2016 drozdz_b
** Last update Sun Mar 27 23:20:16 2016 drozdz_b
*/

#include "my.h"

void	init_map(struct s_case **map, char c, int width, int height)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < height)
    {
      while (i < width)
	{
	  map[i][j].x = i;
	  map[i][j].y = j;
	  map[i][j].nteam = c;
	  ++i;
	}
      i = 0;
      ++j;
    }
}

struct s_case	**create_map(char *pwd, t_map_info *info)
{
  struct s_case	**map;
  void	*addr;
  int	i;

  info->key = ftok(pwd, 0);
  info->width = W_MAP;
  info->height = H_MAP;
  info->shm_id = shmget(info->key, info->width * info->height
			* sizeof(struct s_case), IPC_CREAT | SHM_R | SHM_W);
  addr = shmat(info->shm_id, NULL, SHM_R | SHM_W);
  map = malloc(sizeof(struct s_case) * info->height);
  i = 0;
  while (i < info->height)
    {
      map[i] = addr + i * info->height * sizeof(struct s_case);
      ++i;
    }
  init_map(map, EMPTY_CHAR, info->width, info->height);
  map_add_sem(info);
//  shmdt(addr);
  //map_add_sem(map, info->key, info->width, info->sem_ids);
  return (map);
}

struct s_case	**get_map(char *pwd, t_map_info *info)
{
  struct s_case	**map;
  void	*addr;
  int	i;

  info->key = ftok(pwd, 0);
  info->width = W_MAP;
  info->height = H_MAP;
  info->shm_id = shmget(info->key, info->width * info->height
			* sizeof(struct s_case), SHM_R | SHM_W);
  if (info->shm_id == -1)
    return (NULL);
  addr = shmat(info->shm_id, NULL, SHM_R | SHM_W);
  map = malloc(sizeof(struct s_case) * info->height);
  i = 0;
  while (i < info->height)
    {
      map[i] = addr + i * info->height * sizeof(struct s_case);
      ++i;
    }
  map_add_sem(info);
  //  shmdt(addr);
  //map_add_sem(map, info->key, info->width, info->sem_ids);
  return (map);
}


void	display_map(struct s_case **map, int width, int height)
{
  int	i;
  int	j;

  i = j = -1;
  fprintf(stderr, "+");
  while (++i < width)
      fprintf(stderr, "--");
  fprintf(stderr, "-+\n");
  i = -1;
  while (++j < height)
    {
      fprintf(stderr, "| ");
      while (++i < width)
	{
	  fprintf(stderr, "%c ", map[i][j].nteam + 48);
	}
      i = -1;
      fprintf(stderr, "|\n");
    }
  i = -1;
  fprintf(stderr, "+");
  while (++i < width)
      fprintf(stderr, "--");
  fprintf(stderr, "-+\n");
}

void		free_map(struct s_case **map, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
    {
      shmdt(map[i]);
      ++i;
    }
}
