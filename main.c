/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:09:48 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 12:26:37 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "solve_tang.h"

/*
** The function print_usage_msg() prints a usage message in case users of the
** program need a prompt on how to use it.
*/

void	print_usage_msg(const char *prog_name)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage_msg(argv[0]);
		return (1);
	}
	if (!solve(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
