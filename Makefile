##
## EPITECH PROJECT, 2018
## my_defender
## File description:
## Makefile
##

SRC	=	src/main.c 				\
		src/menu.c 				\
		src/load_game.c 		\
		src/main_char.c 		\
		src/my_pause.c      	\
        src/basic_functions.c   \
        src/move.c				\
		src/battle.c			\
		src/hitboxes_map.c	\
		src/find_battle.c	\
		src/battle2.c	\
		src/battle3.c 	\
		src/quest.c

CC	=	gcc

CFLAGS	=	-I./include -g3 -W

NAME	=	my_rpg

GRAPHICS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(GRAPHICS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
