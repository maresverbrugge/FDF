/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:20:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/09 14:35:58 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h" // for libft
# include "printf/printf.h" // for ft_printf
# include "MLX42/include/MLX42/MLX42.h" // for MLX42
# include "MLX42/include/MLX42/MLX42_Input.h" // for MLX42
# include "MLX42/include/MLX42/MLX42_Int.h" // for MLX42
# include <memory.h> // for MLX42
# include <stdio.h> // for MLX42
# include <stdlib.h> // for malloc, free, exit
# include <unistd.h> // for write, read

// for MLX42
#define WIDTH 256
#define HEIGHT 256

// for GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_data_points
{
	int x;
    int y;
    int z;
}	t_data_points;

typedef struct s_data
{
	int axis;
    int ordinate;
    int altitude;
}	t_data;

#endif