/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tang.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:17:27 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 16:08:17 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_TANG_H
# define SOLVE_TANG_H
# include "read_file.h"
# include "tetrimino_tang.h"
# include "square_tang.h"

void	print_usage_msg(const char *prog_name);
int		solve(const char *filename);
int		get_next_point(t_point **point, char **square);
int		solve_a_square_tang(char **board, int size,
			t_list **block, t_point point);
int		get_next_point_tang(t_point **point, char **square, int size);
void	ft_putstrarr_tang(char **board, int board_size);
#endif
