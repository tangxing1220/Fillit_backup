/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_tang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:40:34 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 16:14:56 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "square_tang.h"

/*
** The function make_square_struct() makes a structure for a square to be
** filled, which contains the size of the square and a string array filled
** with '.'.
*/

char	**create_square_tang(int size)
{
	char	**board;
	int		i;
	int		j;

	board = (char **)ft_memalloc(sizeof(*board) * size);
	if (board == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		board[i] = (char *)malloc(sizeof(char) * size);
		j = 0;
		while (j < size)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
	return (board);
}

void	ft_putstrarr_tang(char **board, int board_size)
{
	int i;
	int j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			write(1, &board[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
