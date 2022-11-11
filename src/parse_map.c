/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 12:11:14 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/11 15:44:16 by mverbrug      ########   odam.nl         */
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
	return (columns);
}

void	remove_newline_str(char *str)
{
	int	i;
	int	str_len;

	i = 0;
	// printf("before str = \n%s\n", str);
	str_len = ft_strlen(str);
	while (i < str_len)
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	// printf("after str = \n%s\n", str);
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
	{
		perror("Error mallocing data_points");
		exit(EXIT_FAILURE);
	}
	// printf("map_data->rows = %d\n", map_data->rows);
	// printf("map_data->columns = %d\n", map_data->columns);
	// printf("map_data->amount_of_points = %d\n", map_data->amount_of_points);
	// printf("map_data->map_as_str = \n%s\n", map_data->map_as_str);
	remove_newline_str(str);
	map_data->str_split = ft_split(str, ' ');
	map_data->int_array = malloc(map_data->amount_of_points * sizeof(int));
	int i = 0;
	while (i < map_data->amount_of_points)
	{
		// printf("map_data->str_split[%d] = %s\n", i, map_data->str_split[i]);
		map_data->int_array[i] = ft_atoi(map_data->str_split[i]);
		// printf("map_data->int_array[%d] = %i\n", i, map_data->int_array[i]);
		i++;
	}
	fill_data_points(map_data);
	close(map_fd);
}
