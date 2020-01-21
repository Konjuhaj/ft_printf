/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/21 18:31:37 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_flag(const char *s, t_data *data)
{
	int i;

	i = -1;
	data->container.filler = ' ';
	while (s[++i] == ' ' || s[i] == '#' || s[i] == '0'
			|| s[i] == '+' || s[i] == '-')
	{
		data->hash = s[i] == '#' ? '#' : data->hash;
		data->container.filler = s[i] == '0' ? '0' : data->container.filler;
		if (data->sign != '+')
			data->sign = s[i] == ' ' ? ' ' : data->sign;
		data->sign = s[i] == '+' ? '+' : data->sign;
		data->allign = s[i] == '-' ? '-' : data->allign;
	}
	data->container.filler = data->allign == '-' ? ' ' : data->container.filler;
	data->i += i;
	return (0);
}

int		is_width(const char *s, t_data *data)
{
	if (*s == '*' || ft_isdigit(*s))
	{
		data->size = *s == '*' ? va_arg(data->arg, int) : ft_atoi(s);
		data->i += ncount(data->size) - 1;
		return (1);
	}
	return (0);
}

int		is_precision(const char *s, t_data *data)
{
	int i;

	i = 0;
	if (*s == '.')
	{
		while (ft_isdigit(s[++i]) || s[i] == '*')
			data->i++;
		data->precision = s[1] == '*' ? va_arg(data->arg, int) : ft_atoi(s + 1);
		return (1);
	}
	return (0);
}

int		is_legth(const char *s, t_data *data)
{
	if ((s[0] == 'h' && s[1] == 'h')
		|| (s[0] == 'l' && s[1] == 'l'))
	{
		data->length = s[0] + s[1];
		data->i++;
		return (1);
	}
	else if (s[0] == 'L' || s[0] == 'h' || s[0] == 'l')
	{
		data->length = s[0];
		return (1);
	}
	return (0);
}

int		is_type(const char *s, t_data *data)
{
	if (*s == 'd' || *s == 'i' || *s == 'u'
		|| *s == 'f' || *s == 'x' || *s == 'X'
		|| *s == 'o' || *s == 'p' || *s == 'b'
		|| *s == 'B')
	{
		data->container.id = NUMBER;
		data->type = *s;
		return (1);
	}
	else if (*s == 's' || *s == 'c' || *s == '%'
			|| *s == 'S' || *s == 't' || *s == 'T')
	{
		data->container.id = TEXT;
		data->type = *s;
		return (1);
	}
	data->container.id = 0;
	return (0);
}
