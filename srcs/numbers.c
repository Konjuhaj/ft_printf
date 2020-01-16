/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/15 09:43:15 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	x_flag(t_data *data)
{
	char			*temp;
	unsigned long	bignum;

	u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, HEXAL);
	if (temp[0] == '0' && data->precision == 0)
	{
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		return ;
	}
	if (!(BUFFER) || data->container.size <= (int)ft_strlen(temp))
	{
		if (bignum != 0)
			BUFFER = data->hash == '#' ? ft_strjoin("0x", temp) : ft_strdup(temp);
		else
			BUFFER = ft_strdup(temp);
		if (data->precision > (int)ft_strlen(BUFFER) && ft_strlen(BUFFER) != 0)
			BUFFER = dot_flag(BUFFER, data);
		free(temp);
	}
	else
		ft_fill(temp, data);
	if (data->type == 'X')
		ft_capitalize(BUFFER);
	data->ret += ft_strlen(BUFFER);
}

void	d_flag_helper(t_data *data, char *temp)
{
	if (BUFFER)
		free(BUFFER);
	BUFFER = data->hash == '#' ? ft_strjoin("0", temp) : temp;
	if (data->precision > (int)ft_strlen(BUFFER))
	{
		data->container.size = ft_strlen(temp);
		create_buffer(temp, data);
		ft_fill(temp, data);
	}
	else if (data->sign != 0 || (temp[0] == '-' && BUFFER[0] == '0'))
		BUFFER = sign_flag(data, temp);
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
	if (temp[0] == '0' && data->precision == 0)
	{
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		if (data->sign == '+')
			BUFFER = sign_flag(data, temp);
		return ;
	}
	if (!(BUFFER) || (data->container.size < (int)ft_strlen(temp)))
		d_flag_helper(data, temp);
	else
		ft_fill(temp, data);
	data->ret += ft_strlen(BUFFER);
}

void	o_flag(t_data *data)
{
	char			*temp;
	unsigned long	bignum;

	bignum = 0;
	u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, OCTAL);
	if (temp[0] == '0' && data->precision <= 0)
	{
		if (BUFFER == NULL && (data->precision != 0 || data->hash == '#'))
			BUFFER = ft_strdup("0");
		else if (data->precision != 0)
			ft_fill(temp, data);
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		return ;
	}
	if (!(BUFFER) || data->container.size <= (int)ft_strlen(temp))
	{
		if (BUFFER)
			free(BUFFER);
		BUFFER = data->hash == '#' ? ft_strjoin("0", temp) : temp;
		if (data->precision > (int)ft_strlen(BUFFER)
			&& ft_strlen(BUFFER) != 0)
			BUFFER = dot_flag(BUFFER, data);
	}
	else
		ft_fill(temp, data);
	data->ret += ft_strlen(BUFFER);
}

void	p_flag(t_data *data)
{
	unsigned long	num;
	char			*temp;
	char			*temp2;

	num = va_arg(data->arg, unsigned long);
	temp2 = ft_uitoa_base(num, HEXAL);
	temp = ft_strjoin("0x", temp2);
	free(temp2);
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		BUFFER = temp;
	}
	else
		ft_fill(temp, data);
}
