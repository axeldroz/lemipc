/*
** my.h for my in /home/drozdz_b/Documents/Unix System/LemIPC/shared_memory
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun Mar 20 12:16:25 2016 drozdz_b
** Last update Sun Mar 27 22:52:05 2016 drozdz_b
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include "lemipc.h"
#include "map.h"

#define CLEAR() fprintf(stderr, "\033[H\033[J")
#define ABS(a) ((a < 0) ? -a : a)
#define SLEEP_TIME 70000
/*
** Sem functions
*/
void	sem_lock(int sem_id);
void	sem_unlock(int sem_id);

/*
** launch_game.c
*/
int	launch_game(int ac, char **av);

/*
** maths_func
*/
int     my_square_root(int nb);

#endif
