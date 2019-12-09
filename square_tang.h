/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_tang.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:42 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 15:58:55 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_TANG_H
# define SQUARE_TANG_H
# include <string.h>

void			print_str_square(char	**square);
char			**create_square_tang(int size);
void			ft_putstrarr_tang(char **board, int board_size);

#endif
