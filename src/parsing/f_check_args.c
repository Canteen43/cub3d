/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:08 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/04 14:14:03 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_check_args(int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		f_error_and_exit(ERR_ARGNBR, 1);
	len = strl(argv[1]);
	if (strcmp(".cub", argv[1] + len - 4))
		f_error_and_exit(ERR_ARGNAME, 1);
}
