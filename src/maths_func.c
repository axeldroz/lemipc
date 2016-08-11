/*
** maths_func.c for maths_func in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu Mar 24 05:36:49 2016 drozdz_b
** Last update Thu Mar 24 05:39:24 2016 drozdz_b
*/

#include "my.h"

int     my_square_root(int nb)
{
  int   root = nb;
  while (root > 0 && root *  root != nb)
    {
      root = root - 1;
    }
  return root;
}
