/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpollore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:40:38 by jpollore          #+#    #+#             */
/*   Updated: 2018/03/08 20:40:30 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points.h"
#include "read.h"
#include "square.h"
#include "tetrimino.h"
#include "square_tang.h"

/*  Begin of Original
int	get_next_point(t_point **point, char **square)
{
	if (!square)
		return (0);
	(*point)->x = (*point)->x + 1;
	while (square[(*point)->y] != NULL)
	{
		while (square[(*point)->y][(*point)->x] != '\0')
		{
			if (square[(*point)->y][(*point)->x] == '.')
				return (1);
			(*point)->x = (*point)->x + 1;
		}
		(*point)->y = (*point)->y + 1;
		(*point)->x = 0;
	}
	return (0);
}
    End of Original */

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

/* Begin of Original
int	solve_a_square(t_square *square, t_list **block, t_point *p_start)
{
	int found;

	found = 0;
	if (!block || !*block)
		return (1);
	while ((!(found = check_tetrimino_fits((t_tetri *)(*block)->content,
			square, p_start)) && get_next_point(&p_start, square->rows)))
		;
	if (!found)
		return (0);
	place_a_tetrimino((t_tetri *)(*block)->content, square, p_start);
	if (!solve_a_square(square, &((*block)->next), create_point(0)))
	{
		remove_a_tetrimino((t_tetri *)(*block)->content, square);
		if (!get_next_point(&p_start, square->rows))
		{
			p_start->x = 0;
			p_start->y = 0;
			return (0);
		}
		return (solve_a_square(square, block, p_start));
	}
	return (1);
}
End of Original */


int	solve_a_square_tang(char **board, int size, t_list **block, t_point *p_start)
{
	int found;

	found = 0;
	if (!block || !*block)
		return (1);
	while ((!(found = check_tetrimino_fits_tang((t_tetri *)(*block)->content,
			board, size, p_start)) && get_next_point_tang(&p_start, board, size)))
		;
	if (!found)
		return (0);
	place_a_tetrimino_tang((t_tetri *)(*block)->content, board, size, p_start);
	if (!solve_a_square_tang(board, size, &((*block)->next), create_point(0)))
	{
		remove_a_tetrimino_tang((t_tetri *)(*block)->content, board, size);
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


/* Begin of Original
int	solve_squares(t_list **tetri_lst)
{
	t_square	*square;
	t_point		*p_start;
	t_list		*tetri_lst_tail;
	size_t		square_size;

	square_size = 2;
	if (!(square = create_square(square_size)))
		return (0);
	if (!(p_start = create_point(0)))
		return (0);
	while ((tetri_lst_tail = *tetri_lst) &&
			!solve_a_square(square, &tetri_lst_tail, p_start))
	{
		free_square(&square);
		if (!(square = create_square(++square_size)))
			return (0);
		p_start->x = 0;
		p_start->y = 0;
	}
	ft_putstrarr(square->rows);
	free_square(&square);
	free(square);
	return (1);
}
 End of Original */

int	solve_squares_tang(t_list **tetri_lst)
{
	char	**board;
	t_point		*p_start;
	t_list		*tetri_lst_head;
	int			board_size;
	int		tetri_cnt;

	tetri_cnt = lstlen_tetri(tetri_lst);
	board_size = 2;
	while((board_size * board_size) < (tetri_cnt * 4))
		{
			board_size++;
		}
	if (!(board = create_square_tang(board_size)))
		return (0);
	if (!(p_start = create_point_tang(0)))
		return (0);
	while ((tetri_lst_head = *tetri_lst) &&
			!solve_a_square_tang(board, board_size, &tetri_lst_head, p_start))
	{
//		free_square(&square);
		if (!(board = create_square_tang(++board_size)))
			return (0);
		p_start->x = 0;
		p_start->y = 0;
	}
	ft_putstrarr_tang(board, board_size);
//	free_square(board;
//	free(square);
	return (1);
}

int	solve(const char *filename)
{
	t_list		*tetri_lst;

	if (!(tetri_lst = get_tetriminoes_from_file(filename)))
		return (0);
/* Begin of original
	if (!solve_squares_tang(&tetri_lst))
   End of original */
	if (!solve_squares_tang(&tetri_lst))
		return (0);
	return (1);
}