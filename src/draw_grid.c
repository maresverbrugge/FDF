/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 18:06:33 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/17 18:06:57 by mverbrug      ########   odam.nl         */
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

void	draw_grid(mlx_image_t *the_map, t_map *map_data)
{
	int	i;

	i = 0;
	draw_horizontal(the_map, map_data);
	draw_vertical(the_map, map_data);
	while (i < map_data->amount_of_points)
	{
		mlx_put_pixel(the_map, 100 + map_data->data_points[i].x,
			100 + map_data->data_points[i].y, 0x00F400FF);
		i++;
	}
}