/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:39:36 by xtang             #+#    #+#             */
/*   Updated: 2019/12/09 15:58:03 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define TETRI_SIZE 20

t_list		*get_tetriminoes_from_file(const char *filename);

#endif
