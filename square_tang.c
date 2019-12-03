/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:36:41 by enennige          #+#    #+#             */
/*   Updated: 2018/03/11 17:24:01 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "square.h"

/*
** The function make_square_str() makes a square array of strings, with a
** width and height equal to size. Each character in the array of strings is
** then initialized to '.'
*/
/*
static char	**make_square_str(size_t size)
{
	char	**square;
	size_t	i;

	if ((square = (char **)ft_memalloc((sizeof(*square) * (size + 1)))))
	{
		i = 0;
		while (i < size)
		{
			if (!(square[i] = ft_strnew(size)))
			{
				while (--i)
					ft_strdel(&square[i]);
				free(square);
				return (NULL);
			}
			ft_memset(square[i++], '.', size);
		}
	}
	return (square);
}
*/
/*
** The function free_square() frees a square structure. Should be called
** once a square structure is no longer needed.
*/
/*
void		free_square(t_square **square)
{
	size_t row;

	if (!square)
		return ;
	row = 0;
	while (row < (*square)->size)
		ft_strdel(&((*square)->rows[row++]));
	free((*square)->rows);
	(*square)->rows = NULL;
	free(*square);
	*square = NULL;
}
*/
/*
** The function update_square() deletes the rows within a square and then
** replaces them with the new content in rows.
*/
/*
void		update_square(t_square **square, char **rows)
{
	size_t row;

	row = 0;
	while (row < (*square)->size)
		ft_strdel(&((*square)->rows[row++]));
	(*square)->rows = rows;
}
*/
/*
** The function make_square_struct() makes a structure for a square to be
** filled, which contains the size of the square and a string array filled
** with '.'.
*/

char	**create_square_tang(int size)
{
	char  **board;
	int i;
	int j;

	board = (char **)ft_memalloc(sizeof(*board) * size);
	if (board == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		board[i] = (char *)malloc (sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
/*	Begin of Debug */
	ft_putstrarr(board);
 /*   End of Debug */	
	return (board);
}
