/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:51:01 by enennige          #+#    #+#             */
/*   Updated: 2018/03/11 17:24:15 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H
# include <string.h>

/* Begin of original */
typedef struct	s_square
{
	size_t		size;
	char		**rows;
}				t_square;
t_square		*create_square(size_t size);
void			print_str_square(char	**square);
void			free_square(t_square **square);
void			update_square(t_square **square, char **rows);

char			**create_square_tang(int size);
void			ft_putstrarr_tang(char **board, int board_size);
#endif
/* end of original */
 
 	

