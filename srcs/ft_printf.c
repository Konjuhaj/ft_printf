/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 18:34:31 by bkonjuha         ###   ########.fr       */
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
		|| s == 'p' || s == '%')
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
	f['%'] = &ft_printcent;
}

int		get_container(const char *src, t_data *data, int i)
{
	void	(*function[126])(t_data *data, int id);

	function_array(function);
	data->i = i + 1;
	if (is_parameter(src + data->i, data))
		data->i += 2;
	if (is_flag(src + data->i, data))
		data->i++;
	if (is_width(src[data->i], data))
		data->i++;
	if (is_precision(src[data->i], data))
		data->i++;
	if (is_legth(src + data->i, data))
		data->i++;
	if (is_type(src[data->i], data))
		data->i++;
	if (data->flag > 0)
		ft_printflag(data);
	function[(int)data->type](data, data->type);
	if (data->flag < 0)
		ft_printflag(data);
	return (data->i);
}

int		ft_printf(const char *format, ...)
{
	t_data	f;
	int		i;

	i = -1;
	f.ret = 0;
	va_start(f.arg, format);
	while (format[++i])
	{
		if (format[i] == '%')
			if (ft_strlen(format) <= (size_t)(i = get_container(format, &f, i)))
				break ;
		f.ret++;
		ft_putchar(format[i]);
	}
	va_end(f.arg);
	return (f.ret);
}
