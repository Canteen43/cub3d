/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:20:37 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 10:26:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// Buffer size in our file reading functions.
# define BUFFER_SIZE 256

// Width of game window.
# define WIDTH 1280

// Height of game window.
# define HEIGHT 720

// Pi, the circle number.
# define PI 3.14159265359

// Height and width of minimap
# define MINI_HEIGHT 240

// Sets how much can be seen on minimap (unit = cubes)
# define DISTANCE_SEEN 8.0

// Horizontal field of view in radians.
// 1 equals 57 degrees.
# define FOV 1.0

// Sets how far the player moves with one button press.
// 0.1 means 10% of cube width.
# define SPEED 0.1

// Sets how much the player turns with one button press. Unit is radians.
// 0.017453293 is PI / 180, so one degree.
// # define ANGLE_SPEED 0.017453293
# define ANGLE_SPEED 0.05

// Sets sleep between frame render.
// Cave: Real value is lower since this assumes instant render.
# define FRAMES_PER_SECOND 80

// Sets a distance between player and wall that shall not be passed
# define WALL_BUFFER 0.2

#endif // MACROS_H
