/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/27 08:39:51 by bkonjuha         ###   ########.fr       */
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
	{
		fill_container(temp, data);
		free(temp);
	}
	if (data->type == 'X')
		ft_capitalize(BUFFER);
	data->ret += ft_strlen(BUFFER);
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
		return ;
	}
	if (!(BUFFER) || (data->container.size < (int)ft_strlen(temp)))
	{
		BUFFER = data->hash == '#' ? ft_strjoin("0", temp) : temp;
		if (data->precision > (int)ft_strlen(BUFFER) && ft_strlen(BUFFER) != 0)
			BUFFER = handle_prsecision(BUFFER, data);
		if (temp[0] == '-' && BUFFER[0] == '0')
			BUFFER = handle_sign(BUFFER);
	}
	else
	{
		fill_container(temp, data);
		free(temp);
	}
	data->ret += ft_strlen(BUFFER);
}

void	ft_printoct(t_data *data, int id)
{
	char			*temp;
	unsigned long	bignum;

	bignum = 0;
	if (id)
		ft_u_typecast(data, &bignum);
	temp = ft_uitoa_base(bignum, OCTAL);
	if (temp[0] == '0' && data->precision == 0 && id)
	{
		if (BUFFER == NULL && data->hash == '#')
			BUFFER = ft_strdup("0");
		data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
		return ;
	}
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		BUFFER = data->hash == '#' ? ft_strjoin("0o", temp) : temp;
		if (data->precision > (int)ft_strlen(BUFFER)
			&& ft_strlen(BUFFER) != 0)
			BUFFER = handle_prsecision(BUFFER, data);
	}
	else
	{
		fill_container(temp, data);
		free(temp);
	}
	data->ret += ft_strlen(BUFFER);
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
	if (!(BUFFER) && id)
	{
		BUFFER = (char *)malloc(sizeof(char) * 2);
		BUFFER[0] = '%';
	}
	else
		fill_container("%", data);
	data->ret += ft_strlen(BUFFER);
}

void	ft_printchar(t_data *data, int id)
{
	char *c;

	c = (char *)malloc(2);
	if (id)
		c[0] = va_arg(data->arg, int);
	c[2] = '\0';
	if ((!(BUFFER) && id) || data->container.size == 0)
	{
		if (!(*c))
		{
			ft_putchar(*c);
			data->ret++;
		}
		BUFFER = c;
	}
	else
	{
		if (!(*c))
		{
			BUFFER[data->size < 0 ? 0 : data->size - 1] = '\0';
			data->ret++;
		}
		fill_container(c, data);
		free(c);
	}
	data->ret += ft_strlen(BUFFER);
}

void	ft_printstr(t_data *data, int id)
{
	char *s;

	s = va_arg(data->arg, char *);
	if (id)
	{
		if (!s)
			s = "(null)";
		if ((!(BUFFER) && id) || (s[0] == '\0' && data->size == 0)
		|| (data->precision > (int)ft_strlen(s) && (int)ft_strlen(s) != 0)
		|| (data->container.size < (int)ft_strlen(s)))
			BUFFER = data->precision > -1 ?
			ft_strsub(s, 0, data->precision) : ft_strdup(s);
		else
			fill_container(s, data);
		data->ret += ft_strlen(BUFFER);
	}
}
