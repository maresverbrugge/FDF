/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   very_quick_maths.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 16:13:49 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/01 16:16:07 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
