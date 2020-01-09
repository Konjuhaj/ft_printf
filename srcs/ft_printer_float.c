/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:17:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/09 14:47:24 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_longfloat(t_data *data)
{
	long double	num;
	char		*temp;

	num = va_arg(data->arg, long double);
	temp = ft_lf_itoa(num, data->precision);
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
		BUFFER = temp;
	else
		ft_fill(temp, data);
}

void		ft_printfloat(t_data *data, int id)
{
	double	num;
	char	*temp;

	num = 0.0;
	if (data->length == 'L')
	{
		ft_longfloat(data);
		return ;
	}
	else if (id)
		num = va_arg(data->arg, double);
	temp = ft_f_itoa(num, data->precision);
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
		BUFFER = temp;
	else
		ft_fill(temp, data);
}
