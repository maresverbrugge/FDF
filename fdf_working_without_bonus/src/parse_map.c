/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 12:11:14 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/01 16:44:14 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	open_map(char **argv)
{
	int		map_fd;

	map_fd = open(argv[1], O_RDONLY);
	if (!map_fd || map_fd < 0)
		error("Error opening map");
	return (map_fd);
}

int	count_rows(char *str)
{
	int		rows;
	char	**map_split_on_newline;

	map_split_on_newline = ft_split(str, '\n');
	if (!map_split_on_newline)
		error("Error splitting str on newline\n");
	rows = 0;
	while (map_split_on_newline[rows])
		rows++;
	free_2d_array(map_split_on_newline);
	return (rows);
}

int	count_columns(char *str)
{
	int		columns;
	char	**split_on_nl;
	char	**split_on_space;

	split_on_nl = ft_split(str, '\n');
	split_on_space = ft_split(split_on_nl[0], ' ');
	columns = 0;
	while (split_on_space[columns])
		columns++;
	free_2d_array(split_on_nl);
	free_2d_array(split_on_space);
	return (columns);
}

void	fill_data_points(t_map *map_data)
{
	int	i;

	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->int_array[i] = ft_atoi(map_data->str_split[i]);
		i++;
	}
	i = 0;
	while (i < map_data->amount_of_points)
	{
		map_data->data_points[i].x = i % map_data->columns;
		map_data->data_points[i].y = i / map_data->columns;
		map_data->data_points[i].z = map_data->int_array[i];
		i++;
	}
}

void	parse_map(char **argv, t_map *map_data)
{
	int		map_fd;
	char	*str;

	map_fd = open_map(argv);
	map_to_str(map_fd, &str);
	map_data->map_as_str = str;
	map_data->rows = count_rows(map_data->map_as_str);
	map_data->columns = count_columns(map_data->map_as_str);
	map_data->amount_of_points = map_data->rows * map_data->columns;
	map_data->data_points
		= malloc(map_data->amount_of_points * sizeof(t_data_point));
	if (!map_data->data_points)
		error("Error mallocing data_points");
	remove_newline_str(str);
	map_data->str_split = ft_split(str, ' ');
	map_data->int_array = malloc(map_data->amount_of_points * sizeof(int));
	fill_data_points(map_data);
	free(str);
	close(map_fd);
}
