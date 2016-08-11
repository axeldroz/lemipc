/*
** sem_func.c for sem_func in /home/drozdz_b/Documents/Unix System/LemIPC/lemip-test2
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Mar 23 20:03:08 2016 drozdz_b
** Last update Wed Mar 23 20:15:25 2016 drozdz_b
*/

#include "my.h"

void	sem_lock(int sem_id)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = -1; // on décrémente donc ça lock
  semop(sem_id, &sops, 1);
}

void	sem_unlock(int sem_id)
{
  struct sembuf	sops;

  sops.sem_num = 0;
  sops.sem_flg = 0;
  sops.sem_op = 1; // on incrémente donc ça unlock
  semop(sem_id, &sops, 1);
}
