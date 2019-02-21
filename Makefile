##
## EPITECH PROJECT, 2018
## 104intersection
## File description:
## compilation
##

SRC		=	$(wildcard *.c)

OBJ		=	$(SRC:.c=.o)

NAME	=	104intersection

RM		=	rm -f -r

$(NAME):	$(OBJ)
		gcc -g $(OBJ) -o $(NAME) -lm
		rm -f $(OBJ)

debug:		CFLAGS += -g
debug:		re

all:    	$(NAME)

clean:
		@$(RM) *~
		@$(RM) *.o
		@printf "Les fichiers ~ et .o ont été supprimé\n"

fclean:		clean
		@$(RM) $(NAME)
		@printf "Le fichier cat a été supprimé\n"

re: 		fclean all
