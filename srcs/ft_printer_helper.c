/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/04 17:35:51 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_typecast(t_data *data, long long *num, int id)
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

void	ft_u_typecast(t_data *data, unsigned long *bignum)
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
	fill_container(temp, data);
	free(temp);
	BUFFER = handle_sign(data, temp);
	if (data->precision < data->container.size
		&& data->precision > (int)ft_strlen(temp))
		update_buffer(data);
}
