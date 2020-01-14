/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/14 17:01:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	typecast(t_data *data, long long *num, int id)
{
	*num = va_arg(data->arg, long long);
	if (data->length == 'h')
		*num = (short)*num;
	else if (data->length == 'h' + 'h')
		*num = (char)*num;
	else if (data->length == 'l')
		*num = (long)*num;
	if ((id == 'd' || id == 'i') && data->length == 0)
		*num = (int)*num;
}

void	u_typecast(t_data *data, unsigned long *bignum)
{
	*bignum = va_arg(data->arg, unsigned long);
	if (data->length == 'h')
		*bignum = (unsigned short)*bignum;
	else if (data->length == 'h' + 'h')
		*bignum = (unsigned char)*bignum;
	else if (data->length == 0)
		*bignum = (unsigned int)*bignum;
}

void	ft_fill(char *temp, t_data *data)
{
	if (data->hash == '#')
	{
		temp = hash_flag(temp, data);
	}
	fill_buffer(temp, data);
	free(temp);
	if (data->precision < data->container.size)
		update_buffer(data, temp);
	if (data->precision >= (int)ft_strlen(temp)
		|| BUFFER[0] == '0' || data->sign)
		BUFFER = sign_flag(data, temp);
}

void	move_right(t_data *data, char sign)
{
	int i;

	i = ft_strlen(BUFFER) - 1;
	while (--i >= 0)
		BUFFER[i + 1] = BUFFER[i];
	BUFFER[0] = sign;
}
