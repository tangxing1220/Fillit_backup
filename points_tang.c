/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_tang.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:37:40 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 13:37:53 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "points_tang.h"

t_point		*create_point_tang(int len)
{
	t_point *point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = len / 5;
	}
	return (point);
}

t_point		*create_point(int len)
{
	t_point *point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = len / 5;
	}
	return (point);
}

void		free_point(t_point **point)
{
	if (!point)
		return ;
	free(*point);
	*point = NULL;
}

void		free_minmax_points(t_point ***points)
{
	if (!points)
		return ;
	free_point(*points + 1);
	free_point(*points);
	free(*points);
	*points = NULL;
}
