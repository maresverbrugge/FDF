/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edit_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/28 12:32:36 by mverbrug      ########   odam.nl         */
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

	max_distance = 20;
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

void	edit_data_points(t_map *map_data)
{
	int	i;
	double degree;

	i = 0;
	degree = 45.0;
	add_spacing(map_data);
	rotation_on_z_axis(map_data, degree);
	rotation_on_x_axis(map_data, degree);
	// rotation_on_y_axis(map_data);
}
