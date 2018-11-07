##
## EPITECH PROJECT, 2018
## Makefile day10
## File description:
## 
##

NAME = grep
NAMETEST = tests_grep
SRC =	src/grep.c \
	src/main.c
SRCTEST = src/grep.c \
	tests/test_grep.c

OBJ =	$(SRC:.c=.o)

INC =	-I./include/ \

CFLAGS= $(INC)	\
	-W	\
	-Wall	\
	-Wextra	\

LDFLAGS= -lmy   \
         -L./lib/my/ \

CC =	gcc

TMPTEST = *.g*

RULE =	all

all:    $(NAME)


$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CDFLAGS)

tests_run:	$(OBJ)
	$(CC) -lcriterion --coverage $(SRCTEST) $(CFLAGS) $(LDFLAGS) -o $(NAMETEST)
	./$(NAMETEST)

clean:
	$(RM) $(OBJ) $(TMPTEST)

fclean:	clean
	$(RM) $(NAME) $(NAMETEST)

re:	fclean all
