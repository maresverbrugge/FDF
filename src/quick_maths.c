/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_maths.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 16:13:49 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/01 16:16:22 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double	degree_to_rad(double degree)
{
	return (degree * (M_PI / 180));
}

int	calc_map_length(t_map *map_data)
{
	int	map_length;

	map_length = find_biggest_x(map_data) - find_smallest_x(map_data);
	return (map_length);
}

int	calc_map_width(t_map *map_data)
{
	int	map_width;

	map_width = find_biggest_y(map_data) - find_smallest_y(map_data);
	return (map_width);
}

int	calc_space_x(t_map *map_data)
{
	int	space;
	int	max_distance;

	max_distance = 25;
	space = MAP_LENGTH / map_data->columns;
	if (space > max_distance)
		return (max_distance);
	else
		return (space);
}

int	calc_space_y(t_map *map_data)
{
	int	space;
	int	max_distance;

	max_distance = 25;
	space = MAP_WIDTH / map_data->rows;
	if (space > max_distance)
		return (max_distance);
	else
		return (space);
}
