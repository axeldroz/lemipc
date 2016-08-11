/*
** main.c for main in /home/drozdz_b/Documents/Unix System/LemIPC/shared_memory
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Sun Mar 20 12:16:52 2016 drozdz_b
** Last update Mon Apr 04 18:44:28 2016 drozdz_b
*/

#include "my.h"

int		main(int ac, char **av)
{
  if (ac < 2)
    {
      fprintf(stderr, "Usage : %s <pwd>\n", av[0]);
      return (0);
    }
  srand(time(NULL));
  launch_game(ac, av);
  return (0);
}
