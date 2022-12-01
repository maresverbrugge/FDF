/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 18:06:33 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/01 14:54:48 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	absolute(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}

int	ternary(int a, int b, int result_a, int result_b)
{
	if (a < b)
		return (result_a);
	else
		return (result_b);
}

void	bresenham(mlx_image_t *the_map, t_map *map_data, int direction, int i)
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

	start_x = map_data->data_points[i].x;
	start_y = map_data->data_points[i].y;
	if (direction == 1)
	{
		end_x = map_data->data_points[i + 1].x;
		end_y = map_data->data_points[i + 1].y;
	}
	if (direction == 2)
	{
		end_x = map_data->data_points[i + map_data->columns].x;
		end_y = map_data->data_points[i + map_data->columns].y;
	}
	delta_x = absolute(end_x - start_x);
	delta_y = -absolute(end_y - start_y);
	sx = ternary(start_x, end_x, 1, -1);
	sy = ternary(start_y, end_y, 1, -1);
	error = delta_x + delta_y;
	while (1)
	{
		if (!(start_x < 0 || start_x >= MAP_LENGTH || start_y < 0 || start_y >= MAP_WIDTH))
			mlx_put_pixel(the_map, start_x, start_y, 0x00cc33FF);
		if (start_x == end_x && start_y == end_y)
			break ;
		error2 = 2 * error;
		if (error2 >= delta_y)
		{
			if (start_x == end_x)
				break ;
			error += delta_y;
			start_x += sx;
		}
		if (error2 <= delta_x)
		{
			if (start_y == end_y)
				break ;
			error += delta_x;
			start_y += sy;
		}
	}
}

void	draw_grid(mlx_image_t *the_map, t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		if (i % map_data->columns == (map_data->columns - 1))
		{
			i++;
			continue ;
		}
		bresenham(the_map, map_data, 1, i);
		i++;
	}
	i = 0;
	while (i < map_data->amount_of_points - map_data->columns)
	{
		bresenham(the_map, map_data, 2, i);
		i++;
	}
}
