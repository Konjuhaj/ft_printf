/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 18:58:47 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(long long num, int base, t_data *data)
{
	int n;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num >= (long long)base)
	{
		ft_putnbr_base(num / base, base, data);
		n = num % base >= 10 ? num % base + 'a' - 10 : num % base + 48;
	}
	else
		n = num >= 10 ? num + 'a' - 10 : num + 48;
	if (data->type == 'X' && n >= 'a')
		n -= 32;
	ft_putchar(n);
	data->ret++;
}

void	ft_printnum(t_data *data, int id)
{
	long long num;

	num = (va_arg(data->arg, long long));
	if (data->length == 'h')
		num = (short)num;
	else if (data->length == 'h' + 'h')
		num = (char)num;
	else if (data->length == 'l')
		num = (long)num;
	if (id == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(num, HEXAL, data);
	}
	else if (id == 'x' || id == 'X')
		ft_putnbr_base((unsigned int)num, HEXAL, data);
	else if (id == 'i' || id == 'd' || id == 'u')
		ft_putnbr_base(num = id == 'u' ? (unsigned int)num : (int)num, DECIMAL, data);
	else if (id == 'o')
		ft_putnbr_base(num, OCTAL, data);
	else if (id == 'b')
		ft_printbit((int)num);
	data->length = 0;
}

void	ft_printcent(t_data *data, int id)
{
	if (id)
		ft_putchar('%');
	data->ret++;
}

void	ft_printchar(t_data *data, int id)
{
	if (id)
		ft_putchar(va_arg(data->arg, int));
	data->ret++;
}

void	ft_printstr(t_data *data, int id)
{
	if (id)
		ft_putstr(va_arg(data->arg, char *));
	data->ret += ft_strlen(va_arg(data->arg, char *));
}
