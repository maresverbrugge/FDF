/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:20:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/10 12:52:39 by mverbrug      ########   odam.nl         */
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
# include <fcntl.h> // for open

// for MLX42
#define WIDTH 256
#define HEIGHT 256

// for GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_data_point
{
	int x;
    int y;
    int z;
}	t_data_point;

typedef struct s_map
{
	int rows;
    int columns;
    int data_points;
    t_data_point *data_points;
}	t_map;

void	parse_map(char **argv, t_map *map_data);
int     map_to_str(int fd, char **map);

#endif