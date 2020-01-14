/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/14 13:15:31 by bkonjuha         ###   ########.fr       */
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

int		is_type(const char *s, t_data *data)
{
	if (*s == 'd' || *s == 'i' || *s == 'u'
		|| *s == 'f' || *s == 'x' || *s == 'X'
		|| *s == 'o')
	{
		data->container.id = NUMBER;
		data->type = *s;
		return (1);
	}
	else if (*s == 's' || *s == 'c'
		|| *s == 'p' || *s == '%')
	{
		data->container.id = TEXT;
		data->type = *s;
		return (1);
	}
	data->container.id = 0;
	return (0);
}

void	function_array(void (*f[])(), int (*f2[])())
{
	f['c'] = &c_flag;
	f['s'] = &s_flag;
	f['x'] = &x_flag;
	f['X'] = &x_flag;
	f['o'] = &o_flag;
	f['p'] = &p_flag;
	f['i'] = &d_flag;
	f['d'] = &d_flag;
	f['u'] = &d_flag;
	f['%'] = &percent_flag;
	f['f'] = &f_flag;
	f2[0] = &is_parameter;
	f2[1] = &is_flag;
	f2[2] = &is_width;
	f2[3] = &is_precision;
	f2[4] = &is_legth;
	f2[5] = &is_type;
	f2[6] = &create_buffer;
}

int		read_flags(const char *src, t_data *data, int i)
{
	void	(*function[126])(t_data *data, int id);
	int		(*params[7])(const char *s, t_data *data);
	int		remember;

	function_array(function, params);
	data->i = i + 1;
	remember = i + 1;
	i = -1;
	while (++i < 7)
		data->i = (params[i])(src + data->i, data) ? ++data->i : data->i;
	if (data->container.id == 0)
		return (ft_default(data, remember));
	function[(int)data->type](data, data->type);
	if (BUFFER == NULL)
		return (data->i);
	i = -1;
	while (++i < (int)ft_strlen(BUFFER) || i < data->size)
		ft_putchar(BUFFER[i]);
	return (data->i);
}

int		ft_printf(const char *format, ...)
{
	t_data	f;
	int		i;

	i = 0;
	f.ret = 0;
	f.container.buffer = NULL;
	f.length = 0;
	va_start(f.arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = read_flags(format, &f, i);
			free(f.container.buffer);
			f.container.buffer = NULL;
			if (ft_strlen(format) <= (size_t)i)
				break ;
			continue ;
		}
		f.ret++;
		ft_putchar(format[i++]);
	}
	va_end(f.arg);
	return (f.ret);
}
