/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_s_c.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 15:41:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:40:02 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_put_char(char c, t_ret *ret)
{
	write(1, &c, 1);
	ret->count++;
	return ;
}

void	ft_put_str(char *str, t_ret *ret)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_put_char(str[i], ret);
		i++;
	}
	return ;
}

void	ft_converse_str(va_list args, t_ret *ret)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_put_str(str, ret);
	return ;
}

void	ft_converse_c(va_list args, t_ret *ret)
{
	unsigned char	c;

	c = va_arg(args, int);
	ft_put_char(c, ret);
	return ;
}
