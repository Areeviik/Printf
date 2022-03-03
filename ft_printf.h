/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:17:39 by akhachat          #+#    #+#             */
/*   Updated: 2021/04/19 16:59:55 by akhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_flags
{
	int			dot; //.
	int			minus; 
	int			asterisk; //*
	int			width; 
	int			zero;
}				t_flags;

int				ft_putstr(char *str);
int 			ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_printf_hex(va_list argument, t_flags *flag);
void			ft_init_flags(t_flags *flag);
int				ft_dig_p(unsigned long long n, int len, char *base);
int				ft_putnbr_base_p(unsigned long long nbr);
int				ft_printf_p(va_list argument, t_flags *flag);
int				ft_int_len_p(unsigned long long a);
int				ft_putnbr_base(long n, int len, char *base);
int				ft_printf_s(va_list args, t_flags *flag);
int				ft_printf_d(va_list argument, t_flags *flag);
int				ft_printf_c(va_list args, t_flags *flag);
int				ft_conv_check(const char *format, int i, va_list args,
				t_flags *flag);
int				ft_putchar(char c);
int				ft_int_len(int n, int k);
int				ft_int_len_u(unsigned int n, int k);
int				ft_flag_check(const char *format, int i, va_list args,
				t_flags *flag);
int				ft_printf(const char *format, ...);
int				ft_printf_upperhex(va_list argument, t_flags *flag);
int				ft_printf_percent(t_flags *flag);
int				ft_printf_u_2(unsigned int a,
				t_flags *flag, int spaces, int out);
int				ft_printf_d_2(int a, t_flags *flag, int spaces, int out);
int				ft_flag_check_2(const char *format, int i, va_list args,
				t_flags *flag);
int				ft_printf_hex_2(unsigned int a, t_flags *flag, int spaces,
				int out);
int				ft_printf_upperhex_2(unsigned int a, t_flags *flag, int spaces,
				int out);
int				ft_flag_check_3(const char *format, int i, va_list args,
				t_flags *flag);
int				ft_printf_u(va_list argument, t_flags *flag);

#endif
