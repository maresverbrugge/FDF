/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/22 12:41:37 by mverbrug      ########   odam.nl         */
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

void	edit_data_points(t_map *map_data)
{
	int	i;
	int previous_x;
    int previous_y;
	int	z;
	double rad;

	i = 0;
	rad = degree_to_rad(30.0);
	printf("rad = %f\n", rad);
	while (i < map_data->amount_of_points)
	{
		previous_x = map_data->data_points[i].x;
		previous_y = map_data->data_points[i].y;
		z = map_data->data_points[i].z;
		// map_data->data_points[i].x = ((previous_x - previous_y) * cos(rad))* 10;
		// map_data->data_points[i].y = (-z + (previous_x + previous_y) * sin(rad)) * 10;

		map_data->data_points[i].x = ((previous_x * cos(rad)) - (previous_y * sin(rad)))* 10;
		map_data->data_points[i].y = (-z + (previous_x * sin(rad)) + (previous_y * cos(rad)))* 10;

		// map_data->data_points[i].x = (i % map_data->columns) * 42;
		// printf("x = %i\t", map_data->data_points[i].x);
		// map_data->data_points[i].y = (i / map_data->columns) * 42;
		// printf("y = %i\t", map_data->data_points[i].y);
		// map_data->data_points[i].z = map_data->int_array[i];
		// printf("z = %i\t\n", map_data->data_points[i].z);
		i++;
	}


	// #include <math.h>
	// int hoek = 65 * (M_PI / 180.0);
	// float old_x = 5.0;
	// float old_y = 5.0;
	// float new_x = old_x * cos(hoek) - old_y * sin(hoek);
	// float new_y = old_x * sin(hoek) + old_y * cos(hoek);
	// ft_printf("x = %d\n", new_x);
	// ft_printf("y = %d\n", new_y);
}

