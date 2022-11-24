/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 18:06:33 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/24 16:06:44 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"


void	draw_horizontal(mlx_image_t *the_map, t_map *map_data)
{
	int	i;
	int	x_start;
	int	x_end;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		x_start = map_data->data_points[i].x;
		x_end = map_data->data_points[i + 1].x;
		while (x_start < x_end)
		{
			mlx_put_pixel(the_map, 100 + x_start,
				100 + map_data->data_points[i].y, 0xF652F6FF);
			x_start++;
		}
		i++;
	}
}

void	draw_vertical(mlx_image_t *the_map, t_map *map_data)
{
	int	i;
	int	y_start;
	int	y_end;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		y_start = map_data->data_points[i].y;
		y_end = map_data->data_points[i + map_data->columns].y;
		while (y_start < y_end)
		{
			mlx_put_pixel(the_map, 100 + map_data->data_points[i].x,
				100 + y_start, 0x00828282);
			y_start++;
		}
		i++;
	}
}

int	absolute(int number)
{
	if (number < 0)
		number *= -1;
	return (number);
}

void	bresenham(mlx_image_t *the_map, t_map *map_data, int direction, int i)
{
	int	delta_x;
	int	delta_y;
	int sx;
	int sy;
	int error;
	int error2;
	int start_x;
	int end_x;
	int start_y;
	int end_y;
	// int gradient;

	// gradient = map_data->data_points[i].z / 100;
	// printf("gradient = %d\n", gradient);

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
	sx = (start_x < end_x) ? 1 : -1;
	sy = (start_y < end_y) ? 1 : -1;
	error = delta_x + delta_y;
	while (1)
	{
		mlx_put_pixel(the_map, 100 + start_x,
			100 + start_y, 0x00F400FF);
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
	// draw_horizontal(the_map, map_data);
	// draw_vertical(the_map, map_data);
	while (i < map_data->amount_of_points)
	{
		if (i % map_data->columns == (map_data->columns - 1))
		{
			i++;
			continue;
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



// void	bresenham(mlx_image_t *the_map, int start_x, int end_x, int start_y, int end_y)
// {
// 	int	delta_x;
// 	int	delta_y;
// 	int sx;
// 	int sy;
// 	int error;
// 	int error2;

// 	delta_x = absolute(end_x - start_x);
// 	delta_y = -absolute(end_y - start_y);
// 	sx = (start_x < end_x) ? 1 : -1;
// 	sy = (start_y < end_y) ? 1 : -1;
// 	error = delta_x + delta_y;
// 	while (1)
// 	{
// 		mlx_put_pixel(the_map, 100 + start_x,
// 			100 + start_y, 0x00F400FF);
// 		if (start_x == end_x && start_y == end_y)
// 			break ;
// 		error2 = 2 * error;
// 		if (error2 >= delta_y)
// 		{
// 			if (start_x == end_x)
// 				break ;
// 			error += delta_y;
// 			start_x += sx;
// 		}
// 		if (error2 <= delta_x)
// 		{
// 			if (start_y == end_y)
// 				break ;
// 			error += delta_x;
// 			start_y += sy;
// 		}
// 	}
// }


// void	draw_grid(mlx_image_t *the_map, t_map *map_data)
// {
// 	int	i;
// 	int	start_x = 0;
// 	int	end_x = 0;
// 	int	start_y = 0;
// 	int	end_y = 0;

// 	i = 0;
//	// draw_horizontal(the_map, map_data);
//	// draw_vertical(the_map, map_data);
// 	while (i < map_data->amount_of_points)
// 	{
// 		if (i % map_data->columns == (map_data->columns - 1))
// 		{
// 			i++;
// 			continue;
// 		}
// 		start_x = map_data->data_points[i].x;
// 		end_x = map_data->data_points[i + 1].x;
// 		start_y = map_data->data_points[i].y;
// 		end_y = map_data->data_points[i + 1].y;
// 		bresenham(the_map, start_x, end_x, start_y, end_y);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < map_data->amount_of_points - map_data->columns)
// 	{
// 		start_x = map_data->data_points[i].x;
// 		end_x = map_data->data_points[i + map_data->columns].x;
// 		start_y = map_data->data_points[i].y;
// 		end_y = map_data->data_points[i + map_data->columns].y;
// 		bresenham(the_map, start_x, end_x, start_y, end_y);
// 		i++;
// 	}
// }
