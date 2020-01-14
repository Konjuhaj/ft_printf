/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:17:41 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/14 13:40:08 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	Lf_flag(t_data *data)
{
	long double	*num;
	char		*temp;

	num = (long double *)ft_memalloc(sizeof(long double));
	*num = va_arg(data->arg, long double);
	temp = ft_lf_itoa(*num, data->precision);
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
		BUFFER = temp;
	else
		ft_fill(temp, data);
}

void		f_flag(t_data *data, int id)
{
	double	num;
	char	*temp;

	num = 0.0;
	if (data->length == 'L')
	{
		Lf_flag(data);
		return ;
	}
	else if (id)
		num = va_arg(data->arg, double);
	temp = ft_f_itoa(num, data->precision);
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		if (data->sign == ' ' && ft_isdigit(temp[0]) == 1)
			ft_putchar(data->sign);
		BUFFER = temp;
	}
	else
		ft_fill(temp, data);
	if (data->hash && data->precision == 0)
	{
		temp = ft_strjoin(BUFFER, ".");
		free(BUFFER);
		BUFFER = temp;
	}
}
