/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:20:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/05 12:52:16 by mverbrug      ########   odam.nl         */
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
# include <math.h> // for cos and sin

// for MLX42
# define SCREEN_WIDTH 1500
# define SCREEN_LENGTH 1500
# define MAP_WIDTH 1500
# define MAP_LENGTH 1500

// for map_to_str
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_data_point
{
	int	x;
	int	y;
	int	z;
}	t_data_point;

typedef struct s_map
{
	char			*map_as_str;
	char			**str_split;
	int				*int_array;
	int				rows;
	int				columns;
	int				amount_of_points;
	t_data_point	*data_points;
}	t_map;

typedef struct s_bresenham
{
	int	delta_x;
	int	delta_y;
	int	sx;
	int	sy;
	int	error;
	int	error2;
	int	start_x;
	int	end_x;
	int	start_y;
	int	end_y;
}	t_bresenham;

int		open_map(char **argv);
int		count_rows(char *str);
int		count_columns(char *str);
void	fill_data_points(t_map *map_data);
void	parse_map(char **argv, t_map *map_data);

void	rotation_on_z_axis(t_map *map_data, double degree);
void	rotation_on_x_axis(t_map *map_data, double degree);
void	add_spacing(t_map *map_data);
void	center_map(t_map *map_data);
void	edit_data_points(t_map *map_data);

int		absolute(int number);
int		ternary(int a, int b, int result_a, int result_b);
void	bresenham(mlx_image_t *the_map, t_bresenham *bres);
void	bresenham_input(mlx_image_t *the_map,
			t_map *map_data, int direction, int i);
void	draw_grid(mlx_image_t *the_map, t_map *map_data);

void	remove_newline_str(char *str);
char	*join_str(char *s1, char *s2);
int		map_to_str(int fd, char **map);

void	errno_error(void);
void	error(char *msg);
void	free_all(t_map *map_data);
char	*free_2d_array(char **array_2d);

double	degree_to_rad(double degree);
int		calc_map_length(t_map *map_data);
int		calc_map_width(t_map *map_data);
int		calc_space_x(t_map *map_data);
int		calc_space_y(t_map *map_data);

int		find_smallest_x(t_map *map_data);
int		find_smallest_y(t_map *map_data);
int		find_biggest_x(t_map *map_data);
int		find_biggest_y(t_map *map_data);

#endif
