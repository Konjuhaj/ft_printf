/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/19 18:31:08 by bkonjuha         ###   ########.fr       */
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
		data->id = NUMBER;
		data->type = *s;
		return (1);
	}
	else if (*s == 's' || *s == 'c'
		|| *s == 'p' || *s == '%')
	{
		data->id = TEXT;
		data->type = *s;
		return (1);
	}
	return (0);
}

void	function_array(void (*f[])(), int (*f2[])())
{

	f['c'] = &ft_printchar;
	f['s'] = &ft_printstr;
	f['x'] = &ft_printhex;
	f['X'] = &ft_printhex;
	f['o'] = &ft_printoct;
	// f['p'] = &ft_printnum;
	f['i'] = &ft_printdec;
	f['d'] = &ft_printdec;
	f['u'] = &ft_printdec;
	f['%'] = &ft_printcent;
	f2[0] = &is_parameter;
	f2[1] = &is_flag;
	f2[2] = &is_width;
	f2[3] = &is_precision;
	f2[4] = &is_legth;
	f2[5] = &is_type;
}

int		get_container(const char *src, t_data *data, int i)
{
	void	(*function[126])(t_data *data, int id);
	int		(*params[6])(const char *s, t_data *data);

	function_array(function, params);
	data->i = i + 1;
	i = -1;
	while (++i < 6)
		data->i = (params[i])(src + data->i, data) ? ++data->i : data->i;
	function[(int)data->type](data, data->type);
	i = -1;
	while (++i < (int)ft_strlen(data->container) || i < data->size)
		ft_putchar(data->container[i]);
	return (data->i);
}

int		ft_printf(const char *format, ...)
{
	t_data	f;
	int		i;

	i = 0;
	f.ret = 0;
	f.container = NULL;
	f.length = 0;
	va_start(f.arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i = get_container(format, &f, i);
			free(f.container);
			f.container = NULL;
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
