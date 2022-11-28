/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:20:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/28 10:32:16 by mverbrug      ########   odam.nl         */
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

#include <math.h> 

// for MLX42
#define WIDTH 1000 // 256
#define HEIGHT 1000 // 256

// for map_to_str
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
	char *map_as_str;
    char **str_split;
    int *int_array;
    int rows;
    int columns;
    int amount_of_points;
    t_data_point *data_points;
}	t_map;

void	parse_map(char **argv, t_map *map_data);
int     map_to_str(int fd, char **map);
void	fill_data_points(t_map *map_data);
int     get_next_line(int fd, char **line);
char	*free_2d_array(char **array_2d);
void	edit_data_points(t_map *map_data);
void	draw_grid(mlx_image_t *the_map, t_map *map_data);
void	remove_newline_str(char *str);

#endif