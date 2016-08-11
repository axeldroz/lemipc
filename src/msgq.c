/*
** msgq.c for msgq in /home/gilber_l/rendu/PSU_2015_lemipc
**
** Made by luigi luigi
** Login   <gilber_l@epitech.net>
**
** Started on  Wed Mar 23 18:35:14 2016 luigi luigi
** Last update Sun Mar 27 23:31:08 2016 drozdz_b
*/

#include "my.h"

int	get_msg_id(key_t key, t_player *info)
{
  info->msg_id = msgget(key + info->nteam, SHM_R | SHM_W);
  if (info->msg_id == -1)
    {
      info->msg_id = msgget(key + info->nteam, IPC_CREAT | SHM_R | SHM_W);
      info->attribute = 1;
    }
  else
    info->attribute = 0;
  return (0);
}

char	*receive_msg(t_player *info)
{
  t_msg	my_msg;
  char	*str;

  str = malloc(2);
  if (str == NULL)
    return (NULL);
  my_msg.mtype = 2;
  my_msg.mtext[0] = 0;
  my_msg.mtext[1] = 0;
  msgrcv(info->msg_id, &my_msg, sizeof(t_msg), 2, 0);
  str[0] = my_msg.mtext[0];
  str[1] = my_msg.mtext[1];
  return (str);
}

void	send_msg(t_player *info, char s[2])
{
  t_msg	my_msg;

  my_msg.mtype = 2;
  my_msg.mtext[0] = s[0];
  my_msg.mtext[1] = s[1];
  msgsnd(info->msg_id, &my_msg, sizeof(t_msg), 0);
}
