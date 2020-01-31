/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/25 16:59:04 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	typecast(t_data *data, long long *num)
{
	int id;

	id = data->type;
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

/*
** Centrelized filler
** precision behaves differently with 'f' type
*/

void	ft_fill(char *temp, t_data *data)
{
	fill_buffer(temp, data);
	if (data->precision >= (int)ft_strlen(temp) && data->type != 'f')
		update_buffer(data, temp);
	if (data->precision >= (int)ft_strlen(temp)
		|| BUFFER[0] == '0' || data->sign)
		BUFFER = sign_flag(data, temp);
	free(temp);
}

/*
** Move the str in buffer to the right
** to make space for a sign.
*/

void	move_right(t_data *data, char sign)
{
	int i;

	i = ft_strlen(BUFFER) - 1;
	while (--i >= 0)
		BUFFER[i + 1] = BUFFER[i];
	BUFFER[0] = sign;
}

/*
** if # is present we run c(temp) through hash_flag
** if prec > len (numbers get leading zeros | text is unchanged)
** else if prec < len(number is unchaned | text gets truncateds)
** lastly we add leading zeros if need be
*/

int		dot_validator(t_data *data, char **c, int *prec)
{
	int len;

	if (data->hash == '#')
		*c = hash_flag(*c, data);
	len = (int)ft_strlen(*c);
	if (data->container.id == NUMBER)
		*prec = data->precision < len ?
		len : data->precision;
	else if (data->container.id == TEXT)
		*prec = data->precision < len ?
		data->precision : len;
	if (data->precision > len
		&& data->container.id == NUMBER)
		*c = dot_flag(*c, data);
	return (0);
}
