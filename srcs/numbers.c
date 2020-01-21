/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 11:50:40 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/21 11:55:00 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_flag(t_data *data)
{
	char			*temp;
	unsigned long	bignum;

	u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, HEXAL);
	number_hub(data, temp);
}

void	d_flag(t_data *data)
{
	long long		num;
	unsigned long	bignum;
	char			*temp;

	bignum = 0;
	if (data->type == 'u')
		u_typecast(data, &bignum);
	else
		typecast(data, &num);
	temp = data->type != 'u' ? ft_itoa_base(num, DECIMAL) :
						ft_uitoa_base(bignum, DECIMAL);
	number_hub(data, temp);
}

void	o_flag(t_data *data)
{
	char			*temp;
	unsigned long	bignum;

	bignum = 0;
	u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, OCTAL);
	number_hub(data, temp);
}

void	p_flag(t_data *data)
{
	unsigned long	num;
	char			*temp;
	char			*temp2;
	char			*temp3;

	num = va_arg(data->arg, unsigned long);
	temp2 = ft_uitoa_base(num, HEXAL);
	if (data->precision >= 0 && ft_strlen(temp2) < 2)
	{
		temp3 = ft_strnew((size_t)data->precision + 1);
		ft_memset(temp3, '0', data->precision);
		if (!(ft_strcmp(temp2, "0")))
		{
			free(temp2);
			temp2 = temp3;
		}
	}
	temp = ft_strjoin("0x", temp2);
	if (!(BUFFER) || data->size < (int)ft_strlen(temp))
		BUFFER = temp;
	else
		ft_fill(temp, data);
	data->ret += ft_strlen(BUFFER);
	free(temp2);
}
