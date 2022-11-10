/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 12:11:14 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/10 12:39:20 by mverbrug      ########   odam.nl         */
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
		exit(EXIT_FAILURE);
	rows = 0;
	while (map_split_on_newline[rows])
		rows++;
	return (rows);
}

int	count_columns(char *str)
{
	int	columns;
	int	i;
	
	columns = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		if (str[i] != ' ')
			columns++;
		i++;
	}
	return (columns);
}

// void	parse_input(char *str)
// {
// 	char	**data_points;

// 	data_points = ft_split(str, ' ');
// 	if (!data_points)
// 		exit(EXIT_FAILURE);
// 	size_t i = 0;
// 	while (data_points[i])
// 	{
// 		printf("data_points[%zu] = %s\n", i, data_points[i]);
// 		i++;
// 	}
// }

void	parse_map(char **argv, t_map *map_data)
{
	int		map_fd;
	char	*map_in_str;

	map_fd = open_map(argv);
	map_to_str(map_fd, &map_in_str);
	close(map_fd);
    printf("map_in_str = \n%s", map_in_str);

    map_data->rows = count_rows(map_in_str);
    map_data->columns = count_columns(map_in_str);
    map_data->data_points = map_data->rows * map_data->columns;
	// printf("rows1 = %d\n", map_data->rows);
	// printf("column1 = %d\n", map_data->columns);
	// printf("data_points1 = %d\n", map_data->data_points);
}