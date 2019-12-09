/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_tang.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:25:25 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 16:04:36 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINO_TANG_H
# define TETRIMINO_TANG_H
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n'
# include <string.h>
# include "points_tang.h"

typedef struct	s_tetri
{
	char		**shape;
	t_point		*start;
	int			width;
	int			height;
}				t_tetri;
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
t_list			*lstnew_tetri(const char *str, char fill);
char			**create_tetrimno_shape(int height, int width);
void			lstdel_tetri(void *content, size_t content_size);
void			free_tetrimino(t_tetri **tetri);
int				validate_tetrimino(const char *shape, t_point ***points);
int				lstadd_tetri(t_list **head, t_list **tail, char *t_str,
							int t_count);
t_tetri			*create_tetrimino(const char *raw_shape, const char fill);
int				lstlen_tetri(t_list **tetri);
int				check_tetrimino_fits_tang(t_tetri *tetrimino, char **board,
							int size, t_point *point);
void			place_a_tetrimino_tang(t_tetri *tetrimino, char **board,
							t_point *point);
void			remove_a_tetrimino_tang(t_tetri *tetrimino, char **board);

#endif
