/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enennige <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:41:47 by enennige          #+#    #+#             */
/*   Updated: 2018/03/11 17:23:46 by enennige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetrimino.h"

/*
** creates a new linked list element for a tetrimino
*/

t_list	*lstnew_tetri(const char *str, char fill)
{
	t_tetri	*tetri;
	t_list	*node;

	if (!(tetri = create_tetrimino(str, fill)))
		return (NULL);
	if (!(node = ft_lstnew((void *)tetri, sizeof(*tetri))))
	{
		free_tetrimino(&tetri);
		return (NULL);
	}
	return (node);
}

/*
** Frees a list of tetriminoes
*/

void	lstdel_tetri(void *content, size_t content_size)
{
	(void)content_size;
	free_tetrimino((t_tetri **)&content);
}

/*
** The function lstadd_tetri() adds a tetrimino to the tlist of tetriminoes,
** assigning the correct letter for the tetriminoes' order.
*/

int		lstadd_tetri(t_list **head, t_list **tail, char *t_str, int t_count)
{
	if (t_count && ((*tail)->next =
		lstnew_tetri(t_str, 'A' + t_count)))
		*tail = (*tail)->next;
	else if ((*head = lstnew_tetri(t_str, 'A' + t_count)))
		*tail = *head;
	else
	{
		ft_lstdel(head, &lstdel_tetri);
		return (-1);
	}
	return (0);
}

/*
**	count the length of tetrimino list
*/

int	 lstlen_tetri(t_list **tetri)
{
	int count;
	t_list *tmp;

	count = 1;
	tmp = *tetri;
	if (tetri == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);		
}
