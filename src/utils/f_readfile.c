/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:40:33 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:07:43 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Gets a fd from a file that needs to be ready to be read from. Returns a
pointer to the string read.*/
char	*f_readfile(t_game *game, int fd)
{
	char	*str;
	char	buf[BUFFER_SIZE];
	int		read_rt;

	str = f_gc_malloc(game, sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	while (1)
	{
		f_bzero(buf, BUFFER_SIZE);
		read_rt = read(fd, buf, BUFFER_SIZE - 1);
		if (read_rt == -1)
			return (NULL);
		if (read_rt == 0)
			break ;
		str = f_strjoin(game, str, buf);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}
