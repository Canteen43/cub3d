/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:49:02 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

/*STANDARD HEADERS*/

// For open(), close()
# include <fcntl.h>
// For read(), write()
# include <unistd.h>
// For printf()
# include <stdio.h>
// For f_gc_malloc(game, ), free()
# include <stdlib.h>
// For perror(), strerror()
# include <string.h>
// For exit()
# include <stdlib.h>
// For gettimeofday()
# include <sys/time.h>
// For booleans
# include <stdbool.h>
// For sin and cos
# include <math.h>
// For keycodes
# include <X11/keysym.h>
// For gettimeofday()
# include <sys/time.h>

/*LOCAL HEADERS*/

// For MLX
# include "mlx.h"
// For color macros
# include "colors.h"
// For regular macros
# include "macros.h"
// For structs, typedefs etc.
# include "structs.h"
// For our functions
# include "functions.h"

#endif // HEADERS_H
