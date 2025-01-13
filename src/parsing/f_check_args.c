/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:08 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 17:16:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_check_args(t_main *main, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		f_graceful_exit(main, 1, __func__, "Wrong nbr of args.");
	len = f_strlen(argv[1]);
	if (strcmp(".cub", argv[1] + len - 4))
		f_graceful_exit(main, 1, __func__, "Arg has to end with '.cub'.");
}
