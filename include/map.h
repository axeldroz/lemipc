/*
** map.h for map in /home/drozdz_b/rendu/PSU_2015_lemipc
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Wed Mar 23 21:39:49 2016 drozdz_b
** Last update Sun Mar 27 23:30:37 2016 drozdz_b
*/

#ifndef MAP_H_
#define MAP_H_

#include "my.h"

#define W_MAP 20
#define H_MAP 20
#define EMPTY_CHAR -16

typedef struct	s_player
{
  int		x;
  int		y;
  int		nteam;
  int		attribute;
  int		msg_id;
}t_player;

typedef struct	s_map_info
{
  key_t		key;
  char		*pwd;
  int		width;
  int		height;
  int		shm_id;
  int		f_sem_id;
  int		shm_ids[W_MAP];
  int		sem_ids[W_MAP][H_MAP];
}t_map_info;

/*
** Fonction pour gérer la map
*/
struct s_case	**create_map(char *, t_map_info *);
struct s_case  	**get_map(char *, t_map_info *);
void    	init_map(struct s_case **, char, int, int);
void    	display_map(struct s_case **, int, int);
void    	free_map(struct s_case **, size_t);

/*
** Fonctions pour gérer semaphore de la map
*/
int	map_add_sem(t_map_info *);
void	map_del_sem(int [W_MAP][H_MAP], int, int);
void	map_fill_case(struct s_case **map, t_map_info info, t_player p);
void   	map_clean_case(struct s_case **map, t_map_info info, t_player p);
void	display_sem(int sem_ids[W_MAP][H_MAP]);

/*
** Fonctions player.c et player2.c
*/
void	player_move(struct s_case **map, t_map_info, t_player *, struct s_case);
int	put_player(struct s_case **map, t_map_info info, t_player *player);
int	player_assaut(struct s_case **map, t_map_info *map_info, t_player *player);
void	launch_player(struct s_case **map, t_map_info *map_info, t_player *player);
int	zbir_action(struct s_case **map, t_map_info *, t_player *);
int		cowar_action(struct s_case **map, t_map_info *map_info, t_player *player);

/*
** Fonctions ia.c, ia2.c et ia3.c
*/
struct s_case		create_case(int x, int y, int nteam);
struct s_case		*get_enemy_array(struct s_case **map, int nteam, int *len);
int			get_distance(t_player p, struct s_case e);
struct s_case		get_closest(struct s_case **map, t_player player, int *len);
struct s_case		get_dir(struct s_case *enemy, t_player *player);
int			*get_player_around(struct s_case **map, int x, int y);
int			is_dead(struct s_case **map, t_player *player);
struct s_case		get_closest_friend(struct s_case **map, t_player player, int *len);
struct s_case		*get_friend_array(struct s_case **map, int nteam, int *len);
struct s_case		get_closest_empty(struct s_case **map, t_player player, int *len);

/*
** Fonctions msgq.c
*/
typedef struct	s_msg
{
  long		mtype;
  char		mtext[2];
}		t_msg;

int	get_msg_id(key_t key, t_player *info);
char	*receive_msg(t_player *info);
void	send_msg(t_player *info, char s[2]);

#endif
