/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:32:20 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 16:57:04 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points_tang.h"
#include "read_file.h"
#include "tetrimino_tang.h"
#include "square_tang.h"

int	get_next_point_tang(t_point **point, char **board, int size)
{
	if (!board)
		return (0);
	while ((*point)->y < size)
	{
		(*point)->x = (*point)->x + 1;
		while ((*point)->x < size)
		{
			if (board[(*point)->y][(*point)->x] == '.')
				return (1);
			else
				(*point)->x = (*point)->x + 1;
		}
		(*point)->x = -1;
		(*point)->y = (*point)->y + 1;
	}
	return (0);
}

int	solve_a_square_tang(char **board, int size,
		t_list **block, t_point *p_start)
{
	int found;

	found = 0;
	if (!block || !*block)
		return (1);
	while ((!(found = check_tetrimino_fits_tang((t_tetri *)(*block)->content,
			board, size, p_start)) &&
				get_next_point_tang(&p_start, board, size)))
		;
	if (!found)
		return (0);
	place_a_tetrimino_tang((t_tetri *)(*block)->content, board, p_start);
	if (!solve_a_square_tang(board, size, &((*block)->next),
				create_point_tang(0)))
	{
		remove_a_tetrimino_tang((t_tetri *)(*block)->content, board);
		if (!get_next_point_tang(&p_start, board, size))
		{
			p_start->x = 0;
			p_start->y = 0;
			return (0);
		}
		return (solve_a_square_tang(board, size, block, p_start));
	}
	return (1);
}

int	solve_squares_tang(t_list **tetri_lst)
{
	char	**board;
	t_point	*p_start;
	t_list	*tetri_lst_head;
	int		board_size;
	int		tetri_cnt;

	tetri_cnt = lstlen_tetri(tetri_lst);
	board_size = 2;
	while ((board_size * board_size) < (tetri_cnt * 4))
		board_size++;
	if (!(board = create_square_tang(board_size)))
		return (0);
	if (!(p_start = create_point_tang(0)))
		return (0);
	while ((tetri_lst_head = *tetri_lst) &&
			!solve_a_square_tang(board, board_size, &tetri_lst_head, p_start))
	{
		if (!(board = create_square_tang(++board_size)))
			return (0);
		p_start->x = 0;
		p_start->y = 0;
	}
	ft_putstrarr_tang(board, board_size);
	return (1);
}

int	solve(const char *filename)
{
	t_list		*tetri_lst;

	if (!(tetri_lst = get_tetriminoes_from_file(filename)))
		return (0);
	if (!solve_squares_tang(&tetri_lst))
		return (0);
	return (1);
}
