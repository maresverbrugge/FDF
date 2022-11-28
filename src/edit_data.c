/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edit_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/28 14:44:54 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	degree_to_rad(double degree)
{
	return (degree * (M_PI / 180));
}

void	rotation_on_z_axis(t_map *map_data, double degree)
{
	int	i;
	double rad;
	int old_x;
    int old_y;

	i = 0;
	rad = degree_to_rad(degree);
	while (i < map_data->amount_of_points)
	{
		old_x = map_data->data_points[i].x;
		old_y = map_data->data_points[i].y;
		map_data->data_points[i].x = ((old_x * cos(rad)) - (old_y * sin(rad))) + 100;
		map_data->data_points[i].y = ((old_x * sin(rad)) + (old_y * cos(rad))) + 100;
		i++;
	}
}

void	rotation_on_x_axis(t_map *map_data, double degree)
{
	int	i;
	double rad;
    int old_y;
	int	old_z;

	i = 0;
	rad = degree_to_rad(degree);
	while (i < map_data->amount_of_points)
	{
		old_y = map_data->data_points[i].y;
		old_z = map_data->data_points[i].z;
		map_data->data_points[i].y = (((old_y * cos(rad)) - (old_z * sin(rad)))) + 100;
		// map_data->data_points[i].z = ((old_y * sin(rad)) + (old_z * cos(rad)));
		i++;
	}
}

// void	rotation_on_y_axis(t_map *map_data, double degree)
// {
// 	int	i;
// 	double rad;
//  int old_x;
// 	int	old_z;

// 	i = 0;
// 	rad = degree_to_rad(degree);
// 	while (i < map_data->amount_of_points)
// 	{
// 		old_x = map_data->data_points[i].x;
// 		old_z = map_data->data_points[i].z;
// 		map_data->data_points[i].x = ((old_x * cos(rad)) + (old_z * sin(rad)));
// 		map_data->data_points[i].z = ((-old_x * sin(rad)) + (old_z * cos(rad)));
// 		i++;
// 	}
// }

int	calc_space(t_map *map_data, int axis)
{
	int space;
	int	max_distance;
	int	axis_size;

	max_distance = 25;
	if (axis == map_data->columns)
		axis_size = MAP_LENGTH;
	if (axis == map_data->rows)
		axis_size = MAP_WIDTH;
	space = axis_size / axis;
	if (space > max_distance)
		return (max_distance);
	else
		return (space);
}

void	add_spacing(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x *= calc_space(map_data, map_data->columns);
		map_data->data_points[i].y *= calc_space(map_data, map_data->rows);
		i++;
	}
}

int	find_smallest_x(t_map *map_data)
{
	int	i;
	int	smallest_x;

	i = 1;
	smallest_x = map_data->data_points[0].x;
	while (i < map_data->amount_of_points)
	{
		if (map_data->data_points[i].x < smallest_x)
			smallest_x = map_data->data_points[i].x;
		i++;
	}
	return (smallest_x);
}

int	find_smallest_y(t_map *map_data)
{
	int	i;
	int	smallest_y;

	i = 1;
	smallest_y = map_data->data_points[0].y;
	while (i < map_data->amount_of_points)
	{
		if (map_data->data_points[i].y < smallest_y)
			smallest_y = map_data->data_points[i].y;
		i++;
	}
	return (smallest_y);
}

int	find_biggest_x(t_map *map_data)
{
	int	i;
	int	biggest_x;

	i = 1;
	biggest_x = map_data->data_points[0].x;
	while (i < map_data->amount_of_points)
	{
		if (map_data->data_points[i].x > biggest_x)
			biggest_x = map_data->data_points[i].x;
		i++;
	}
	return (biggest_x);
}

int	find_biggest_y(t_map *map_data)
{
	int	i;
	int	biggest_y;

	i = 1;
	biggest_y = map_data->data_points[0].y;
	while (i < map_data->amount_of_points)
	{
		if (map_data->data_points[i].y > biggest_y)
			biggest_y = map_data->data_points[i].y;
		i++;
	}
	return (biggest_y);
}

int calc_map_length(t_map *map_data)
{
	int map_length;

	map_length = find_biggest_x(map_data) - find_smallest_x(map_data);
	return (map_length);
}

int calc_map_width(t_map *map_data)
{
	int map_width;

	map_width = find_biggest_y(map_data) - find_smallest_y(map_data);
	return (map_width);
}

void center_map(t_map *map_data)
{
	int	map_length;
	int	map_width;
	int	smallest_x;
	int	i;

	map_length = calc_map_length(map_data);
	map_width = calc_map_width(map_data);
	smallest_x = find_smallest_x(map_data);
	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x = map_data->data_points[i].x
			+ (SCREEN_LENGTH / 2) + abs(smallest_x) - (map_length / 2);
		map_data->data_points[i].y = map_data->data_points[i].y
			+ (SCREEN_WIDTH / 2) - (map_width / 2);
		i++;
	}
}

void	edit_data_points(t_map *map_data)
{
	int	i;
	double degree;

	i = 0;
	degree = 45.0;
	add_spacing(map_data);
	rotation_on_z_axis(map_data, degree);
	rotation_on_x_axis(map_data, degree);
	// center_map(map_data);
}
