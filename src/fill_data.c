/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/22 16:11:48 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_data_points(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x = i % map_data->columns;
		printf("x = %i\t", map_data->data_points[i].x);
		map_data->data_points[i].y = i / map_data->columns;
		printf("y = %i\t", map_data->data_points[i].y);
		map_data->data_points[i].z = map_data->int_array[i];
		printf("z = %i\t\n", map_data->data_points[i].z);
		i++;
	}
}

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
		map_data->data_points[i].x = ((old_x * cos(rad)) - (old_y * sin(rad)));
		map_data->data_points[i].y = ((old_x * sin(rad)) + (old_y * cos(rad)));
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
		map_data->data_points[i].y = ((old_y * cos(rad)) - (old_z * sin(rad)));
		i++;
	}
}

// void	rotation_on_y_axis(t_map *map_data, double degree)
// {
// 	int	i;
// 	double rad;
//     int old_x;
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

void	add_spacing(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x *= 10;
		map_data->data_points[i].y *= 10;
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



// #include <math.h>
// int hoek = 65 * (M_PI / 180.0);
// float old_x = 5.0;
// float old_y = 5.0;
// float new_x = old_x * cos(hoek) - old_y * sin(hoek);
// float new_y = old_x * sin(hoek) + old_y * cos(hoek);
// ft_printf("x = %d\n", new_x);
// ft_printf("y = %d\n", new_y);

