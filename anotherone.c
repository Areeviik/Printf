/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anotherone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:40:34 by akhachat          #+#    #+#             */
/*   Updated: 2021/04/19 16:07:00 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_printf_hex(va_list argument, t_flags *flag)
{
	int				out;
	unsigned int	a;
	int				spaces;
	int				zeros;
	char			zero;

	out = 0;
	zero = ' ';
	a = va_arg(argument, unsigned int);
	zeros = (flag->dot - ft_int_len_u(a, 16) < 0
	? 0 : flag->dot - ft_int_len_u(a, 16));
	spaces = ((a == 0 && flag->dot == 0)
	? flag->width - zeros : flag->width - ft_int_len_u(a, 16) - zeros);
	zero = (flag->dot >= 0) ? '0' : ' ';
	if (spaces > 0 && flag->minus == 0 && flag->zero == 0)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	if (zeros > 0)
		while (zeros-- > 0)
			out += ft_putchar(zero);
	out = ft_printf_hex_2(a, flag, spaces, out);
	return (out);
}

int			ft_printf_hex_2(unsigned int a, t_flags *flag, int spaces, int out)
{
	if (flag->zero == 1)
		while (spaces-- > 0)
			out += ft_putchar('0');
	if (a < 0)
		out += ft_putnbr_base(4294967295 + a, 16, "0123456789abcdef");
	if (a != 0 || flag->dot != 0)
		out += ft_putnbr_base(a, 16, "0123456789abcdef");
	if (flag->minus == 1)
		while (spaces-- > 0)
			out += ft_putchar(' ');
	return (out);
}
