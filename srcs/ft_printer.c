/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/12 11:22:45 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_buffer(int n, int filler)
{
	char *buffer;

	if (n < 0)
		n *= -1;
	buffer = (char *)malloc(sizeof(char) * n + 1);
	ft_memset(buffer, filler, n);
	return (buffer);
}

void	fill_container(char *c, t_data *data)
{
	size_t start;
	size_t destlen;
	size_t	srclen;

	destlen = ft_strlen(data->container);
	srclen = ft_strlen(c);
	if (data->flag > 0)
	{
		start = destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(data->container + start, c, destlen - start);
	}
	else
		ft_strncpy(data->container, c, srclen);
}
void	ft_printhex(t_data *data, int id)
{
	long long num;

	if (id)
		num = va_arg(data->arg, long long);
	if (data->length == 'h')
		num = (short)num;
	else if (data->length == 'h' + 'h')
		num = (char)num;
	else if (data->length == 'l')
		num = (long)num;
	else if (data->length != 'l' + 'l')
		num = (unsigned int)num;
	if(!(data->container))
		data->container = ft_itoa_base(num, HEXAL);
	else
		fill_container(ft_itoa_base(num, HEXAL), data);
	if (data->type == 'X')
		ft_capitalize(data->container);
	data->ret += ft_strlen(data->container);
}

void	ft_printdec(t_data *data, int id)
{
	long long num;
	unsigned long midnum;
	unsigned long long bignum;

	midnum = 0;
	if (id == 'u' && data->length == 'l' + 'l')
		bignum = va_arg(data->arg, unsigned long long);
	else if(id == 'u' && data->length == 'l')
	 	num = va_arg(data->arg, int);
	else
		num = va_arg(data->arg, long long);
	if (data->length == 'h')
		num = (short)num;
	else if (data->length == 'h' + 'h')
		num = (char)num;
	else if(data->length == 'l' && id == 'u')
	{
		midnum = (unsigned long)num;
		bignum = midnum;
	}
	else if (data->length == 'l')
		num = (long)num;
	else if (id == 'd' && data->length == 0)
		num = (int)num;
	else if (id == 'u' && data->length == 0)
		num = (unsigned int)num;
	if(!(data->container))
		data->container = !bignum ? ft_itoa_base(num, DECIMAL) : ft_uitoa_base(bignum, DECIMAL);
	else
		fill_container(ft_itoa_base(!num ? bignum : num, DECIMAL), data);
	data->ret += ft_strlen(data->container);
}

void	ft_printoct(t_data *data, int id)
{
	long long num;

	if (id)
		num = va_arg(data->arg, long long);
	if (data->length == 'h')
		num = (short)num;
	else if (data->length == 'h' + 'h')
		num = (char)num;
	else if (data->length == 'l')
		num = (long)num;
	else if (data->length != 'l' + 'l')
		num = (unsigned int)num;
	if(!(data->container))
		data->container = ft_itoa_base(num, OCTAL);
	else
		fill_container(ft_itoa_base(num, OCTAL), data);
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
	if(!(data->container) && id)
		data->container = "%";
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
	if(!(data->container) && id)
		data->container = c;
	else
		fill_container(c, data);
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
	if(!(data->container) && id)
		data->container = ft_strdup(s);
	else
		fill_container(s, data);
	data->ret += ft_strlen(data->container);
	}
}
