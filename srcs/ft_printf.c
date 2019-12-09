/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 12:00:23 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	parameter(int num, va_list args)
{
	va_list args2;

	va_copy(args2, args);
	while (--num)
	{
		va_arg(args2, char*);
	}
	ft_putstr(va_arg(args2, char*));
	va_end(args2);
}

int		is_type(char s, t_data *data)
{
	if (s == 'd' || s == 'i' || s == 'u'
		|| s == 'f' || s == 'x' || s == 'X'
		|| s == 'o' || s == 's' || s == 'c'
		|| s == 'p')
	{
		data->type = s;
		return (1);
	}
	return (0);
}

void	function_array(void (*f[])())
{

	f['c'] = &ft_printchar;
	f['s'] = &ft_printstr;
	f['x'] = &ft_printnum;
	f['X'] = &ft_printnum;
	f['o'] = &ft_printnum;
	f['p'] = &ft_printnum;
	f['i'] = &ft_printnum;
	f['d'] = &ft_printnum;
	f['u'] = &ft_printnum;
}

int		get_container(const char *src, t_data *data, int i)
{
	void	(*function[126])(t_data *data, int id);

	function_array(function);
	data->i = i + 1;
	if (is_parameter(src + data->i, data))
		data->i += 2;
	if (is_flag(src[data->i], data))
		data->i++;
	if (is_width(src[data->i], data))
		data->i++;
	if (is_precision(src[data->i], data))
		data->i++;
	if (is_legth(src + data->i, data))
		data->i++;
	if (is_type(src[data->i], data))
		data->i++;
	if (!(data->container = (char *)malloc(sizeof(char) * (data->i - i + 1))))
		return (0);
	function[(int)data->type](data, data->type);
	return (data->i);
}

void	ft_printf(const char *format, ...)
{
	t_data	f;
	int		i;

	i = -1;
	va_start(f.arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = get_container(format, &f, i);
		ft_putchar(format[i]);
	}
	va_end(f.arg);
}
