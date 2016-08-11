/*
 * Please be mindful of epitech syntaxic rules when you code in C ;)
 * header, norm, even on this file.
 */

#ifndef LEMIPC_H__
# define LEMIPC_H__

/*
 * This is the structure that you must use to represent a champion
 * You can EXTEND it, but never change the base fields that are already
 * there. Failure to comply will result in a project failure.
 *
 * Your shared memory must be an array of this structure.
 * The size must be of width * height * sizeof(struct s_case)
 */

struct  s_case
{
  /*
   * Position in the map
   */
  int   x;
  int   y;

  /*
   * Team number
   * A value of 0 means that the case is unnocupied
   */
  int   nteam;

  /* Add fields there */
};

/*
 * Note: We MIGHT add fields to the structure so don't use raw numbers for
 * your shm length, use the sizeof keyword
 */

#endif
