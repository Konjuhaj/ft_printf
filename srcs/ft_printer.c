/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 14:43:26 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(long long num, int base)
{
	int n;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num >= (long long)base && base != 2)
	{
		ft_putnbr_base(num / base, base);
		n = num % base >= 10 ? num % base + 'a' - 10 : num % base + 48;
		ft_putchar(n);
	}
	else if (base != 2)
	{
		n = num >= 10 ? num + 'a' - 10 : num + 48;
		ft_putchar(n);
	}
}

void	ft_printnum(t_data *data, int id)
{
	unsigned long long num;

	num = (unsigned long long)(va_arg(data->arg, void *));
	if (id == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_base(num, HEXAL);
	}
	else if (id == 'x')
		ft_putnbr_base(num, HEXAL);
	else if (id == 'i' || id == 'd' || id == 'u')
		ft_putnbr_base(num, DECIMAL);
	else if (id == 'o')
		ft_putnbr_base(num, OCTAL);
	else if (id == 'b')
		ft_printbit((int)num);
}

void	ft_printchar(t_data *data, int id)
{
	if (id)
		ft_putchar(va_arg(data->arg, int));
}

void	ft_printstr(t_data *data, int id)
{
	if (id)
		ft_putstr(va_arg(data->arg, char *));
}
