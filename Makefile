##
## Makefile for Makefile in /home/drozdz_b/Documents/Unix System/LemIPC/test_semaphore
##
## Made by drozdz_b
## Login   <drozdz_b@epitech.net>
##
## Started on  Sat Mar 19 16:37:34 2016 drozdz_b
## Last update Thu Aug 11 16:35:40 2016 drozdz_b
##

SRC	=	src/main.c		\
		src/map.c		\
		src/map_sem.c		\
		src/player.c		\
		src/sem_func.c		\
		src/game.c		\
		src/msgq.c		\
		src/ia.c		\
		src/maths_func.c 	\
		src/ia2.c		\
		src/player2.c		\
		src/ia3.c

NAME	=	lemipc

OBJ	=	$(SRC:.c=.o)

RM	=	rm -rf

CC	=	gcc -I./include/ -Wall -Wextra -Werror -W

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
