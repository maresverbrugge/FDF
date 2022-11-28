/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 12:11:14 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/28 12:10:34 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	open_map(char **argv)
{
	int		map_fd;

	map_fd = open(argv[1], O_RDONLY);
	if (!map_fd || map_fd < 0)
	{
		perror("Error opening map");
		exit(EXIT_FAILURE);
	}
	return (map_fd);
}

char	*free_2d_array(char **array_2d)
{
	size_t	i;

	i = 0;
	while (array_2d[i])
	{
		free(array_2d[i]);
		i++;
	}
	free(array_2d);
	return (NULL);
}

int	count_rows(char *str)
{
	int		rows;
	char	**map_split_on_newline;

	map_split_on_newline = ft_split(str, '\n');
	if (!map_split_on_newline)
	{
		perror("Error splitting str on newline\n");
		exit(EXIT_FAILURE);
	}
	rows = 0;
	while (map_split_on_newline[rows])
		rows++;
	free_2d_array(map_split_on_newline);
	// int i = 0;
	// while (map_split_on_newline[i])
	// {
	// 	free(map_split_on_newline[i]);
	// 	i++;
	// }
	// free(map_split_on_newline);
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
	// printf("columns = %d\n", columns);
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
		map_data->data_points[i].x = i % map_data->columns;
		printf("x = %i\t", map_data->data_points[i].x);
		map_data->data_points[i].y = i / map_data->columns;
		printf("y = %i\t", map_data->data_points[i].y);
		map_data->data_points[i].z = map_data->int_array[i];
		printf("z = %i\t\n", map_data->data_points[i].z);
		i++;
	}
}

void	parse_map(char **argv, t_map *map_data)
{
	int		map_fd;
	char	*str;
	int		i;

	map_fd = open_map(argv);
	map_to_str(map_fd, &str);
	map_data->map_as_str = str;
	map_data->rows = count_rows(map_data->map_as_str);
	map_data->columns = count_columns(map_data->map_as_str);
	map_data->amount_of_points = map_data->rows * map_data->columns;
	map_data->data_points
		= malloc(map_data->amount_of_points * sizeof(t_data_point));
	if (!map_data->data_points)
	{
		perror("Error mallocing data_points");
		exit(EXIT_FAILURE);
	}
	printf("map_data->rows = %d\n", map_data->rows);
	printf("map_data->columns = %d\n", map_data->columns);
	printf("map_data->amount_of_points = %d\n", map_data->amount_of_points);
	// printf("map_data->map_as_str = \n%s\n", map_data->map_as_str);
	remove_newline_str(str);
	map_data->str_split = ft_split(str, ' ');
	map_data->int_array = malloc(map_data->amount_of_points * sizeof(int));
	i = 0;
	while (i < map_data->amount_of_points)
	{
		// printf("map_data->str_split[%d] = %s\n", i, map_data->str_split[i]);
		map_data->int_array[i] = ft_atoi(map_data->str_split[i]);
		// printf("map_data->int_array[%d] = %i\n", i, map_data->int_array[i]);
		i++;
	}
	fill_data_points(map_data);
	// free(map_data->map_as_str);
	free(str);
	close(map_fd);
}
