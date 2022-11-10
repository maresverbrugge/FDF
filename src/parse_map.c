/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/10 12:11:14 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/10 17:36:39 by mverbrug      ########   odam.nl         */
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

void	change_str(char *old_str)
{
	int i;
	char *new_str;
	// int old_len;

    i = 0;
	new_str = NULL;
	// old_len = ft_strlen(old_str);
    while (old_str[i] != '\0')
    {
        printf("old_str[i] = %c\n", old_str[i]);
		// !!!! WERKT NOG NIET FIX DIT AAAH SEG FAULT !!!!
		if (old_str[i] == '\n')
		{
			new_str[i] = ' ';
			i++;
		}	
		else
			new_str[i] = old_str[i];
        i++;
    }
	// new_str[i] = '\0';
	printf("new_str = %s", new_str);
}

void	parse_map(char **argv, t_map *map_data)
{
	int		map_fd;
	char	*str;

	map_fd = open_map(argv);
	map_to_str(map_fd, &str);
	// printf("str = \n%s\n", str);
	change_str(str);

	map_data->map_as_str = str;
	map_data->rows = count_rows(str);
	map_data->columns = count_columns(str);
	map_data->amount_of_points = map_data->rows * map_data->columns;
	map_data->data_points
		= malloc(map_data->amount_of_points * sizeof(t_data_point));
	if (!map_data->data_points)
	{
		perror("Error mallocing data_points");
		exit(EXIT_FAILURE);
	}
	printf("map_data->map_as_str = \n%s\n", map_data->map_as_str);
	printf("map_data->rows = %d\n", map_data->rows);
	printf("map_data->columns = %d\n", map_data->columns);
	printf("map_data->amount_of_points = %d\n", map_data->amount_of_points);
	// fill_data_points(map_data, map_fd);
	close(map_fd);
}
