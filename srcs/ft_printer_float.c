/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:17:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/05 09:27:21 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_f_itoa(double num, int prec)
{
	int			count;
	int			i;
	long long	n;
	char		*temp;

	count = 1;
	prec = prec == -1 ? 6 : prec;
	i = prec;
	while (i != 0 && i--)
		count *= 10;
	n = num * count;
	count = ncount_base(prec == 0 ? n / 10 : n, DECIMAL) + 1;
	i = prec == 0 ? -1 : count - prec;
	if (!(temp = ft_strnew(count + 1)))
		return (NULL);
	temp[count] = '\0';
	if (num < 0)
	{
		temp[0] = '-';
		n *= -1;
	}
	while (--count > -1 && temp[count] != '-')
	{
		if (count == i - 1 && prec != 0)
			temp[count--] = '.';
		temp[count] = n % 10 + '0';
		n /= 10;
	}
	return (temp);
}

void	ft_printfloat(t_data *data, int id)
{
	double	num;
	char	*temp;

	num = 0.0;
	if (id)
		num = va_arg(data->arg, double);
	temp = ft_f_itoa(num, data->precision);
	if (!(BUFFER))
		BUFFER = temp;
	else
	{
		ft_fill(temp, data);
	}

}
