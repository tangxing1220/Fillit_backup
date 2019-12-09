/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_tetrimino_tang.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:37:06 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 13:37:18 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points_tang.h"
#include "tetrimino_tang.h"
#include "square_tang.h"

/*
** Check if tetrimino's first characters are empty, and return an amount to
** shift the tetrimino by in the x direction.
*/

int		tetrimino_xshift_tang(t_tetri *tetri)
{
	int x_shift;

	x_shift = 0;
	while ((tetri->shape)[0][x_shift] == '.')
	{
		x_shift++;
	}
	return (x_shift);
}

/*
** The function check_tetrimino_max() checks if a tetrimino's size will
** overflow a board. Returns 1 if all is good, or 0 if the tetrimino's
** attempted coordinates are outside the board.
*/

int		check_tetrimino_max_tang(t_tetri *tetrimino, int size,
							t_point *point)
{
	if ((point->y + tetrimino->height <= size) &&
		(point->x - tetrimino_xshift_tang(tetrimino) +
		tetrimino->width <= size))
		return (1);
	return (0);
}

/*
** The function check_tetrimino_fits() checks if a tetrimino will fit in a
** grid at a given point. If the tetrimino does not fit, the function
** returns NULL.
*/

int		check_tetrimino_fits_tang(t_tetri *tetrimino, char **board, int size,
							t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	int		xshift;

	tetri_shape = tetrimino->shape;
	if (check_tetrimino_max_tang(tetrimino, size, point) != 1)
		return (0);
	y = 0;
	xshift = tetrimino_xshift_tang(tetrimino);
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (!(board[y + point->y][x - xshift +
				point->x] == '.' ||
				tetri_shape[y][x] == '.'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
** The function place_a_tetrimino() draws a tetrimino on a square board,
** aligning the top left corner of the tetrimino with the point specified.
** The tetrimino is drawn in the character specified (eg. AAAA).
*/

void	place_a_tetrimino_tang(t_tetri *tetrimino, char **board, t_point *point)
{
	int		x;
	int		y;
	char	**tetri_shape;
	int		xshift;

	y = 0;
	tetri_shape = tetrimino->shape;
	xshift = tetrimino_xshift_tang(tetrimino);
	while (tetri_shape[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				board[y + point->y][x - xshift +
				point->x] = tetri_shape[y][x];
			}
			x++;
		}
		y++;
	}
	tetrimino->start->x = (point->x) - xshift;
	tetrimino->start->y = point->y;
}

/*
** The function remove_a_tetrimino() removes a tetrimino from the board
*/

void	remove_a_tetrimino_tang(t_tetri *tetrimino, char **board)
{
	int		x;
	int		y;
	char	**tetri_shape;

	y = 0;
	tetri_shape = tetrimino->shape;
	while ((tetrimino->shape)[y] != NULL)
	{
		x = 0;
		while (tetri_shape[y][x] != '\0')
		{
			if (tetri_shape[y][x] != '.')
			{
				board[y + tetrimino->start->y]
				[x + tetrimino->start->x] = '.';
			}
			x++;
		}
		y++;
	}
}
