/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 12:23:29 by mverbrug      #+#    #+#                 */
/*   Updated: 2022/11/08 15:49:29 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>

typedef struct s_ret
{
	int			count;
}				t_ret;

int		ft_printf(const char	*input, ...);
void	ft_seek_conversion(char conv, va_list args, t_ret *ret);
void	ft_converse_c(va_list args, t_ret *ret);
void	ft_converse_str(va_list args, t_ret *ret);
void	ft_converse_d_i(va_list args, t_ret *ret);
void	ft_converse_u(va_list args, t_ret *ret);
void	ft_converse_hex(va_list args, t_ret *ret, char input);
void	ft_converse_p(va_list args, t_ret *ret);
void	ft_put_nbr(int n, t_ret *ret);
void	ft_put_u(unsigned int n, t_ret *ret);
void	ft_put_char(char c, t_ret *ret);
void	ft_put_str(char *str, t_ret *ret);
void	ft_put_hex(unsigned int n, t_ret *ret);
void	ft_put_hex_up(unsigned int n, t_ret *ret);
void	ft_put_p(unsigned long long n, t_ret *ret);

#endif