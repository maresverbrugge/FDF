/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 15:58:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/10 16:05:29 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// int	get_x(t_map *map_data)
// {
// 	int x;

	
// 	return (x);
// }

void	fill_data_points(t_map *map_data)
{
	int i;
    int arr[map_data->amount_of_points];

	i = 0;
    while (i < map_data->amount_of_points)
    {
        arr[i] = ft_atoi(gesplitte str[index]);
        i++;
    }
    
	
}


    // while (i < map_data->amount_of_points)
	// {
	// 	map_data->data_points[i].x = get_x(&map_data);
	// 	map_data->data_points[i].y = get_y(&map_data);
	// 	map_data->data_points[i].z = get_z(&map_data);
	// 	i++;
	// }