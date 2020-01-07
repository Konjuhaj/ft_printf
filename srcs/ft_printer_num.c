/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/07 09:32:32 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printhex(t_data *data, int id)
{
	char			*temp;
	unsigned long	bignum;

	ft_u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, HEXAL);
	if (temp[0] == '0' && data->precision == 0 && id)
	{
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		return ;
	}
	else if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		if (bignum != 0)
			BUFFER = data->hash == '#' ? ft_strjoin("0x", temp) : temp;
		else
			BUFFER = temp;
		if (data->precision > (int)ft_strlen(BUFFER) && ft_strlen(BUFFER) != 0)
			BUFFER = handle_prsecision(BUFFER, data);
	}
	else
		ft_fill(temp, data);
	if (data->type == 'X')
		ft_capitalize(BUFFER);
	data->ret += ft_strlen(BUFFER);
}

void	ft_decimal_buffer(t_data *data, char *temp)
{
	BUFFER = data->hash == '#' ? ft_strjoin("0", temp) : temp;
	if (data->precision > (int)ft_strlen(BUFFER) && ft_strlen(BUFFER) != 0)
		BUFFER = handle_prsecision(BUFFER, data);
	if (data->sign != 0 || (temp[0] == '-' && BUFFER[0] == '0'))
		BUFFER = handle_sign(data, temp);
}

void	ft_printdec(t_data *data, int id)
{
	long long		num;
	unsigned long	bignum;
	char			*temp;

	bignum = 0;
	if (id == 'u')
		ft_u_typecast(data, &bignum);
	else
		ft_typecast(data, &num, id);
	temp = id != 'u' ? ft_itoa_base(num, DECIMAL) :
						ft_uitoa_base(bignum, DECIMAL);
	if (temp[0] == '0' && data->precision == 0 && id)
	{
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		if (data->sign == '+')
			BUFFER = handle_sign(data, temp);
		return ;
	}
	if (!(BUFFER) || (data->container.size < (int)ft_strlen(temp)))
		ft_decimal_buffer(data, temp);
	else
		ft_fill(temp, data);
	data->ret += ft_strlen(BUFFER);
}

void	ft_printoct(t_data *data, int id)
{
	char			*temp;
	unsigned long	bignum;

	bignum = 0;
	ft_u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, OCTAL);
	if (temp[0] == '0' && data->precision <= 0 && id)
	{
		if (BUFFER == NULL && (data->precision != 0 || data->hash == '#'))
			BUFFER = ft_strdup("0");
		else if (data->precision != 0)
			ft_fill(ft_uitoa_base(0, OCTAL), data);
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		return ;
	}
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		BUFFER = data->hash == '#' ? ft_strjoin("0", temp) : temp;
		if (data->precision > (int)ft_strlen(BUFFER)
			&& ft_strlen(BUFFER) != 0)
			BUFFER = handle_prsecision(BUFFER, data);
	}
	else
		ft_fill(temp, data);
	data->ret += ft_strlen(BUFFER);
}

void	ft_printaddr(t_data *data, int id)
{
	unsigned long	num;
	char			*temp;

	num = va_arg(data->arg, unsigned long);
	temp = ft_strjoin("0x", ft_uitoa_base(num, HEXAL));
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		BUFFER = temp;
	}
	else if (id)
		ft_fill(temp, data);
}
