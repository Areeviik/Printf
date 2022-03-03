/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:17:22 by akhachat          #+#    #+#             */
/*   Updated: 2021/04/19 16:57:49 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_len_u(unsigned int n, int k)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= k;
		++len;
	}
	return (len);
}

int		ft_flag_check(const char *format, int i, va_list args, t_flags *flag)
{
	if (format[i] == '-')
	{
		flag->minus = 1;
		i++;
	}
	if (format[i] == '0')
	{
		flag->zero = 1;
		i++;
	}
	if (format[i] == '-')
	{
		flag->minus = 1;
		i++;
	}
	i = ft_flag_check_3(format, i, args, flag);
	return (i);
}

int		ft_flag_check_3(const char *format, int i, va_list args, t_flags *flag)
{
	if (format[i] == '*')
	{
		flag->width = va_arg(args, int);
		i++;
		if (flag->width < 0)
		{
			flag->minus = 1;
			flag->width = -flag->width;
		}
	}
	i = ft_flag_check_2(format, i, args, flag);
	return (i);
}

int		ft_flag_check_2(const char *format, int i, va_list args, t_flags *flag)
{
	while (ft_isdigit(format[i]))
	{
		flag->width = flag->width * 10 + (format[i] - '0');
		++i;
	}
	if (format[i] == '.')
	{
		flag->dot = 0;
		i++;
		if (format[i] == '*')
		{
			flag->dot = va_arg(args, int);
			i++;
		}
		while (ft_isdigit(format[i]))
		{
			flag->dot = flag->dot * 10 + (format[i] - '0');
			++i;
		}
	}
	flag->zero = (flag->minus == 1) ? 0 : flag->zero;
	flag->zero = (flag->zero == 1 && flag->dot >= 0) ? 0 : flag->zero;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flag;
	int		i;
	int		num;

	num = 0;
	i = -1;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] != '%')
			num += ft_putchar(format[i]);
		else
		{
			ft_init_flags(&flag);
			i = ft_flag_check(format, i + 1, args, &flag);
			num += ft_conv_check(format, i, args, &flag);
		}
	}
	va_end(args);
	return (num);
}
