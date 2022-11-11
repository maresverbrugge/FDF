/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/11 15:43:42 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_data_points(t_map *map_data)
{
    int i = 0;
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
