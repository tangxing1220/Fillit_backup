# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpollore <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/04 08:52:07 by jpollore          #+#    #+#              #
#    Updated: 2019/12/02 18:19:39 by xtang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
LIB_NAME = libft.a
TS_NAME = check.out
TEST_HEADER = $$HOME/.brew/include/
TEST_LIBRARY = $$HOME/.brew/lib/
TEST = tests/
CS = main.c read_file.c tetrimino.c points.c place_tetrimino.c square.c
CS += solve_tang.c lst_util.c tetri_utils.c misc.c
TS = $(filter-out main.c, $(CS))
TC = fillit.check
CFLAGS = -Wall -Wextra -Werror
LIB_OPT = -L. -lft
OBJS = $(patsubst %.c, %.o, $(CS))
TEST_CHECK = $(addprefix $(TEST), $(TC))
TEST_SRC = $(addsuffix .c, $(TEST_CHECK))
OPTION1 = -I. -I./libft/includes
OPTION2 = $(OPTION1) $(LIB_OPT) -I$(TEST_HEADER) -L$(TEST_LIBRARY) -lcheck

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(OPTION1) -g -c $(CS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -g -o $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

make_test: clean_test
	checkmk $(TEST_CHECK) > $(TEST_SRC)
	$(CC) $(CFLAGS) $(OPTION2) $(TEST_SRC) $(TS) -o $(TS_NAME)

run_test: make_test
	./$(TS_NAME); /bin/rm -f $(TS_NAME); /bin/rm -f $(TEST_SRC)

clean_test:
	/bin/rm -f $(TEST_SRC)
	/bin/rm -f $(TS_NAME)
