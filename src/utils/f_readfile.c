/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_readfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:40:33 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 18:11:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Static functions
static void	*f_free_n_ret_null(void *ptr);

/*Gets a fd from a file that needs to be ready to be read from. Returns a
pointer to the string read.*/
char	*f_readfile(int fd)
{
	char	*str;
	char	*old_str;
	char	buf[BUFFER_SIZE];
	int		read_rt;

	str = f_gc_malloc(main, sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = '\0';
	while (1)
	{
		f_bzero(buf, BUFFER_SIZE);
		read_rt = read(fd, buf, BUFFER_SIZE - 1);
		if (read_rt == -1)
			return (f_free_n_ret_null(str));
		if (read_rt == 0)
			break ;
		old_str = str;
		str = f_strjoin(str, buf);
		free(old_str);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

static void	*f_free_n_ret_null(void *ptr)
{
	free(ptr);
	return (NULL);
}
