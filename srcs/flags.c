/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/23 14:21:15 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_parameter(const char *s, t_data *data)
{
	if(ft_isalnum(*s) && s[1] == '$')
	{
		data->param = ft_atoi(s);
		return (1);
	}
	return(0);
}

int		is_flag(const char *s, t_data *data)
{
	int i;

	i = 0;
	data->size = 0;
	data->container.filler = ' ';
	while (s[i] == ' ' || s[i] == '#' || s[i] == '0' || s[i] == '+'|| s[i] == '-')
	{
		if (data->hash != '#')
			data->hash = s[i] == '#' ? '#' : 0;
		if (data->container.filler != '0')
			data->container.filler = s[i] == '0' ? '0' : data->container.filler;
		if (data->sign != '+' && data->sign != '-')
			data->sign = s[i] == ' ' ? ' ' : data->sign;
		if (data->sign != '-')
			data->sign = s[i] == '+' ? '+' : data->sign;
		data->sign = s[i] == '-' ? '-' : data->sign;
		i++;
	}
	if (ft_isdigit(s[i]))
	{
		data->size = ft_atoi(s + i);
		data->container.size = data->size;
		data->i += ncount(data->size) + i - 1;
		data->size = data->sign == '-' ? data->size * -1 : data->size;
		data->container.filler = data->size < 0 ? ' ' : data->container.filler;
		return (1);
	}
	data->container.size = 0;
	data->i += i;
	return (0);
}

int		is_width(const char *s, t_data *data)
{
	if (*s == '*')
	{
		data->width = *s;
		return (1);
	}
	return (0);
}

int		is_precision(const char *s, t_data *data)
{
	data->precision = -1;
	if (*s == '.' || *s == '*')
	{
		data->precision = ft_atoi(s + 1);
		data->i += ft_isdigit(s[1]) ? ncount(data->precision) : 0;
		if ((data->precision > data->container.size) ||
			(data->precision > 0 && s[-1] == '%'))
		{
			data->container.filler = '0';
		}
		return (1);
	}
	return (0);
}

int		is_legth(const char *s, t_data *data)
{
	if ((s[0] == 'h' && s[1] == 'h') ||
			(s[0] == 'l' && s[1] == 'l'))
	{
		data->length = s[0] + s[1];
		data->i++;
		return (1);
	}
	else if (s[0] == 'h' || s[0] == 'l')
	{
		data->length = s[0];
		return (1);
	}
	return (0);
}
