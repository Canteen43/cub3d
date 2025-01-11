/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_dig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:51:20 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 14:51:48 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Returns true if char c is alphabetical, false if not.*/
bool	f_is_dig(char c)
{
	if ((c >= '0' && c <= '9'))
		return (true);
	else
		return (false);
}
