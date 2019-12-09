# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xtang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 13:36:14 by xtang             #+#    #+#              #
#    Updated: 2019/12/09 15:24:30 by xtang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
LIB_NAME = libft.a
TS_NAME = check.out
TEST_HEADER = $$HOME/.brew/include/
TEST_LIBRARY = $$HOME/.brew/lib/
TEST = tests/
CS = main.c read_file.c tetrimino_tang.c points_tang.c place_tetrimino_tang.c square_tang.c
CS += solve_tang.c lst_util.c tetri_utils.c
TS = $(filter-out main.c, $(CS))
TC = fillit.check
CFLAGS = -Wall -Wextra -Werror
LIB_OPT = -L ./libft  -lft
OBJS = $(patsubst %.c, %.o, $(CS))
TEST_CHECK = $(addprefix $(TEST), $(TC))
TEST_SRC = $(addsuffix .c, $(TEST_CHECK))
OPTION1 = -I. -I./libft/includes
OPTION2 = $(OPTION1) $(LIB_OPT) -I$(TEST_HEADER) -L$(TEST_LIBRARY) -lcheck

all: $(NAME)

$(NAME):
	make fclean -C ./libft/
	make -C ./libft/
	$(CC) $(CFLAGS) $(OPTION1) -c $(CS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_OPT) -o $(NAME)

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
