/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/17 18:11:40 by bkonjuha         ###   ########.fr       */
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
	if (id == 'd' && data->length == 0)
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

void	ft_printhex(t_data *data, int id)
{
	char			*temp;
	unsigned long	bignum;

	ft_u_typecast(data, &bignum);
	if (id)
		temp = ft_uitoa_base(bignum, HEXAL);
	if (!(data->container))
	{
		if (bignum != 0)
			data->container = data->hash == '#' ? ft_strjoin("0x", temp) : temp;
		else
			data->container = temp;
	}
	else
	{
		fill_container(temp, data);
		free(temp);
	}
	if (data->type == 'X')
		ft_capitalize(data->container);
	data->ret += ft_strlen(data->container);
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
	if (!(data->container))
		data->container = data->hash == '#' ? ft_strjoin("0", temp) : temp;
	else
	{
		fill_container(temp, data);
		free(temp);
	}
	data->ret += ft_strlen(data->container);
}

void	ft_printoct(t_data *data, int id)
{
	long long		num;
	char			*temp;
	unsigned long	bignum;

	bignum = 0;
	if (id == 'u')
		ft_u_typecast(data, &bignum);
	else
		ft_typecast(data, &num, id);
	temp = id != 'u' ? ft_itoa_base(num, OCTAL) :
						ft_uitoa_base(bignum, OCTAL);
	if (!(data->container))
		data->container = data->hash == '#' ? ft_strjoin("0o", temp) : temp;
	else
	{
		fill_container(temp, data);
		free(temp);
	}
	data->ret += ft_strlen(data->container);
}

// void	ft_printbit_str(t_data *data, int id)
// {
// 	int num;

// 	num = va_arg(data->arg, unsigned int);
// 	data->container = !data->container ? ft_itoa_base(num, HEXAL) :
// 	fill_container(ft_itoa_base(num, HEXAL));
// 	data->ret += ft_strlen(data->container);
// }

void	ft_printcent(t_data *data, int id)
{
	if (!(data->container) && id)
	{
		data->container = (char *)malloc(sizeof(char) * 2);
		data->container[0] = '%';
	}
	else
		fill_container("%", data);
	data->ret += ft_strlen(data->container);
}

void	ft_printchar(t_data *data, int id)
{
	char *c;

	c = (char *)malloc(2);
	if (id)
		c[0] = va_arg(data->arg, int);
	c[2] = '\0';
	if (!(data->container) && id)
		data->container = c;
	else
	{
		fill_container(c, data);
		free(c);
	}
	data->ret += ft_strlen(data->container);
}

void	ft_printstr(t_data *data, int id)
{
	char *s;

	s = va_arg(data->arg, char *);
	if (id)
	{
		if (!s)
			s = "(null)";
		if (!(data->container) && id)
			data->container = ft_strdup(s);
		else
			fill_container(s, data);
		data->ret += ft_strlen(data->container);
	}
}
