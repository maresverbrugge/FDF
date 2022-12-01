/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handle.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/01 16:19:49 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/12/01 16:32:30 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	errno_error(void)
{
	ft_putendl_fd(strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	free_all(t_map *map_data)
{
	free(map_data->data_points);
	free(map_data->int_array);
	free_2d_array(map_data->str_split);
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
