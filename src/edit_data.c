/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edit_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/05 12:34:18 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotation_on_z_axis(t_map *map_data, double degree)
{
	int		i;
	double	rad;
	int		old_x;
	int		old_y;

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
	int		i;
	double	rad;
	int		old_z;
	int		old_y;

	i = 0;
	rad = degree_to_rad(degree);
	while (i < map_data->amount_of_points)
	{
		old_y = map_data->data_points[i].y;
		old_z = map_data->data_points[i].z;
		map_data->data_points[i].y
			= (((old_y * cos(rad)) - (old_z * sin(rad))));
		i++;
	}
}

void	add_spacing(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x *= calc_space_x(map_data);
		map_data->data_points[i].y *= calc_space_y(map_data);
		i++;
	}
}

void	center_map(t_map *map_data)
{
	int	map_length;
	int	map_width;
	int	smallest_x;
	int	smallest_y;
	int	i;

	map_length = calc_map_length(map_data);
	map_width = calc_map_width(map_data);
	smallest_x = find_smallest_x(map_data);
	smallest_y = find_smallest_y(map_data);
	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x
			+= (SCREEN_LENGTH / 2) + abs(smallest_x) - (map_length / 2);
		map_data->data_points[i].y += (SCREEN_WIDTH / 2) + abs(smallest_y) - (map_width / 2);
		i++;
	}
}

// 45.0 and 35.0 degree rotation for sometric projection
void	edit_data_points(t_map *map_data)
{
	double	z_degree;
	double	x_degree;

	z_degree = 45.0;
	x_degree = 45.0;
	add_spacing(map_data);
	rotation_on_z_axis(map_data, z_degree);
	rotation_on_x_axis(map_data, x_degree);
	center_map(map_data);
}
