##
## EPITECH PROJECT, 2021
## projectname
## File description:
## Makefile
##

SRC =	src/connect.c

MAIN = 	src/main.c

OBJ = 	$(SRC:.c=.o) \
		$(MAIN:.c=.o)

NAME = connect4
INC = include/

TEST = unit_tests
TESTS = tests/test_connect.c

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
CPPFLAGS = -I include/
TESTFLAGS = --coverage -lcriterion
LDLIBS = lib/my/libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	make clean -C lib/my/

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	make fclean -C lib/my/

re:	fclean all

tests_run:
	$(RM) *.gcda
	$(RM) *.gcno
	make -C lib/my/
	$(CC) -o $(TEST) $(SRC) $(TESTS) -I $(INC) $(LDLIBS) $(TESTFLAGS)
	./$(TEST)

.PHONY: all clean fclean re tests_run
