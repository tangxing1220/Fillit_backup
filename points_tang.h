/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_tang.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:38:29 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 16:55:48 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_TANG_H
# define POINTS_TANG_H

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;
t_point			*create_point_tang(int len);
void			free_minmax_points(t_point ***points);
void			free_point(t_point **point);

#endif
