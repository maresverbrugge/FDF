/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:12:17 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/18 12:55:44 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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

char	*join_str(char *s1, char *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = malloc(len_s1 + len_s2 + 1);
	if (!joined)
		return (NULL);
	ft_memmove(joined, s1, len_s1);
	ft_memmove(joined + len_s1, s2, len_s2);
	joined[len_s1 + len_s2] = '\0';
	free(s1);
	return (joined);
}

/*
** This function reads input map from a file descriptor  
** It returns 0 if the map has been read.
** It returns -1 if an error happened.
*/

int	map_to_str(int fd, char **map)
{
	int			result;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || map == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*map = NULL;
	result = 1;
	while (result > 0)
	{
		*map = join_str(*map, buf);
		if (*map == NULL)
			return (-1);
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
			return (-1);
		buf[result] = '\0';
	}
	return (0);
}
