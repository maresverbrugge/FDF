/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_i_u.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/05 18:41:56 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:39:33 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void	ft_put_nbr(int n, t_ret *ret)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		ret->count += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ret->count++;
	}
	if (n >= 10)
		ft_put_nbr(n / 10, ret);
	ft_put_char(n % 10 + '0', ret);
	return ;
}

void	ft_put_u(unsigned int n, t_ret *ret)
{
	if (n >= 10)
		ft_put_u(n / 10, ret);
	ft_put_char(n % 10 + '0', ret);
	return ;
}

void	ft_converse_d_i(va_list args, t_ret *ret)
{
	int	d_i;

	d_i = va_arg(args, int);
	ft_put_nbr(d_i, ret);
	return ;
}

void	ft_converse_u(va_list args, t_ret *ret)
{
	unsigned int	u;

	u = va_arg(args, unsigned int);
	ft_put_u(u, ret);
	return ;
}
