/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 18:06:33 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/05 12:56:46 by mverbrug      ########   odam.nl         */
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

void	bresenham(mlx_image_t *the_map, t_bresenham *bres)
{
	while (1)
	{
		if (!(bres->start_x < 0 || bres->start_x >= MAP_LENGTH
				|| bres->start_y < 0 || bres->start_y >= MAP_WIDTH))
			mlx_put_pixel(the_map, bres->start_x, bres->start_y, 0xffcc00FF);
		if (bres->start_x == bres->end_x && bres->start_y == bres->end_y)
			break ;
		bres->error2 = 2 * bres->error;
		if (bres->error2 >= bres->delta_y)
		{
			if (bres->start_x == bres->end_x)
				break ;
			bres->error += bres->delta_y;
			bres->start_x += bres->sx;
		}
		if (bres->error2 <= bres->delta_x)
		{
			if (bres->start_y == bres->end_y)
				break ;
			bres->error += bres->delta_x;
			bres->start_y += bres->sy;
		}
	}
}

void	bresenham_input(mlx_image_t *the_map,
	t_map *map_data, int direction, int i)
{
	t_bresenham	bres;

	bres.start_x = map_data->data_points[i].x;
	bres.start_y = map_data->data_points[i].y;
	if (direction == 1)
	{
		bres.end_x = map_data->data_points[i + 1].x;
		bres.end_y = map_data->data_points[i + 1].y;
	}
	if (direction == 2)
	{
		bres.end_x = map_data->data_points[i + map_data->columns].x;
		bres.end_y = map_data->data_points[i + map_data->columns].y;
	}
	bres.delta_x = absolute(bres.end_x - bres.start_x);
	bres.delta_y = -absolute(bres.end_y - bres.start_y);
	bres.sx = ternary(bres.start_x, bres.end_x, 1, -1);
	bres.sy = ternary(bres.start_y, bres.end_y, 1, -1);
	bres.error = bres.delta_x + bres.delta_y;
	bresenham(the_map, &bres);
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
		bresenham_input(the_map, map_data, 1, i);
		i++;
	}
	i = 0;
	while (i < map_data->amount_of_points - map_data->columns)
	{
		bresenham_input(the_map, map_data, 2, i);
		i++;
	}
}
