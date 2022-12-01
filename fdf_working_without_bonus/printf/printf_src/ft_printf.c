/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 12:22:59 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:39:36 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_seek_conversion(char conv, va_list args, t_ret *ret)
{
	if (conv == 'c')
		ft_converse_c(args, ret);
	if (conv == 's')
		ft_converse_str(args, ret);
	if (conv == 'd' || conv == 'i')
		ft_converse_d_i(args, ret);
	if (conv == 'u')
		ft_converse_u(args, ret);
	if (conv == 'x' || conv == 'X')
		ft_converse_hex(args, ret, conv);
	if (conv == 'p')
		ft_converse_p(args, ret);
	if (conv == '%')
		ft_put_char('%', ret);
	return ;
}

int	ft_printf(const char	*input, ...)
{
	int				i;
	t_ret			ret;
	va_list			args;

	ret.count = 0;
	i = 0;
	va_start(args, input);
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			i++;
			ft_seek_conversion(input[i], args, &ret);
		}
		else
			ft_put_char(input[i], &ret);
		i++;
	}
	va_end(args);
	return (ret.count);
}
