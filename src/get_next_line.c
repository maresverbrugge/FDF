/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:12:17 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:12:19 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (!src || !dst)
		return ;
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_newline(char *s, int c)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (*str == c)
		{
			ft_strcpy(s, str + 1);
			return (1);
		}
		str++;
	}
	return (0);
}

char	*ft_strnjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (ft_strchr(s2, '\n'))
		len_s2 = ft_strchr(s2, '\n') - s2;
	else
		len_s2 = ft_strlen(s2);
	if (len_s1 + len_s2 == 0)
		return (NULL);
	joined = malloc(len_s1 + len_s2 + 1);
	if (!joined)
		return (NULL);
	ft_memmove(joined, s1, len_s1);
	ft_memmove(joined + len_s1, s2, len_s2);
	joined[len_s1 + len_s2] = '\0';
	return (joined);
}

/*
** This function returns a line read from a file descriptor,
** without the newline.
** Returns 1 if a line has been read.
** Returns 0 if EOF has been reached.
** Returns -1 if an error happened.
*/

int	get_next_line(int fd, char **line)
{
	int			result;
	char		*temp;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	result = 1;
	while (result > 0)
	{
		if (*line == NULL)
			temp = "\0";
		else
			temp = *line;
		*line = ft_strnjoin(temp, buf);
		if (ft_newline(buf, '\n'))
			return (1);
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
			return (-1);
		buf[result] = '\0';
	}
	if (result == 0)
		return (0);
	return (1);
}
