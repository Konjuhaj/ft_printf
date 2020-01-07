/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:17:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/07 15:55:11 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_f_itoa(double num, int prec)
{
	int			count;
	int			i;
	int			n;
	char		*temp;

	count = ncount(num);
	i = count + 1;
	prec = prec == -1 ? 6 : prec;
	temp = ft_strnew(prec + 1 + count);
	temp = ft_memcpy(temp, ft_itoa(ft_abs(num) >= 1.0 ? num : 0), count);
	temp[count] = prec == 0 ? 0 : '.';
	num = num < 0 ? num * -1.0 : num;
	n = num;
	num -= (double)n;
	while (i < prec + count + 1)
	{
		temp[i++] = num * 10 + '0';
		num = num * 10;
		n = num;
		num -= (double)n;
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
