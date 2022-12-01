/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x_X_p.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 15:43:35 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:39:25 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_put_hex(unsigned int n, t_ret *ret)
{
	char			*hexa;
	unsigned int	x;

	hexa = "0123456789abcdef";
	if (n > 15)
		ft_put_hex(n / 16, ret);
	x = hexa[n % 16];
	ft_put_char(x, ret);
	return ;
}

void	ft_put_hex_up(unsigned int n, t_ret *ret)
{
	char			*hexa_up;
	unsigned int	x_up;

	hexa_up = "0123456789ABCDEF";
	if (n > 15)
		ft_put_hex_up(n / 16, ret);
	x_up = hexa_up[n % 16];
	ft_put_char(x_up, ret);
	return ;
}

void	ft_put_p(unsigned long long n, t_ret *ret)
{
	char				*hexa;
	unsigned long long	x;

	hexa = "0123456789abcdef";
	if (n > 15)
		ft_put_p(n / 16, ret);
	x = hexa[n % 16];
	ft_put_char(x, ret);
	return ;
}

void	ft_converse_hex(va_list args, t_ret *ret, char input)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	if (input == 'x')
		ft_put_hex(hex, ret);
	if (input == 'X')
		ft_put_hex_up(hex, ret);
	return ;
}

void	ft_converse_p(va_list args, t_ret *ret)
{
	unsigned long long	p;

	p = va_arg(args, unsigned long long);
	ft_put_str("0x", ret);
	ft_put_p(p, ret);
	return ;
}
