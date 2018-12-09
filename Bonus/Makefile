##
## EPITECH PROJECT, 2018
## make
## File description:
## no
##

SRC	=	../src/my_strlen.c \
		../src/my_putchar.c \
		../src/my_putstr.c \
		../src/my_put_nbr.c \
		other_function.c \
		../src/move.c \
		../src/control_map.c

SRCM	=	../src/main.c

OBJ	=	$(SRC:.c=.o)

OBJM	=	$(SRCM:.c=.o)

NAME	=	my_sokoban

INCLUDE =	-I ../include/

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJM)
	gcc -lncurses -o $(NAME) $(OBJ) $(OBJM) $(INCLUDE)
clean:
	rm -f $(OBJ)
	rm -f $(OBJM)
	rm -f */*.gc*
	rm -f *~

%.o: %.c
	gcc -o $@ -c $< -I ../include/

tests_run:
	gcc tests/test.c $(SRC) $(INCLUDE) -o unit_tests --coverage -lcriterion
	./unit_tests

fclean: clean
	rm -f $(NAME)

re: fclean
	rm -f all
