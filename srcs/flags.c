/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/18 13:24:33 by bkonjuha         ###   ########.fr       */
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

int		is_flag(const char *c, t_data *data)
{
	int i;

	i = 0;
	data->flag = 0;
	data->filler = ' ';
	while (c[i] == ' ' || c[i] == '#' || c[i] == '0')
	{
		if (data->hash != '#')
			data->hash = c[i] == '#' ? '#' : 0;
		if (data->filler != '0')
			data->filler = c[i] == '0' ? '0' : data->filler;
		i++;
	}
	if (c[i] == '+' || c[i] == '-' || ft_isdigit(c[i]))
	{
		data->flag = ft_atoi(c + i);
		while((c[i] == '-' || c[i] == '+') && c[i + 1] == '0')
			i++;
		data->container = get_buffer(data->flag, data);
		data->i += data->flag < 0 ? ncount(data->flag) + i - 1: ncount(data->flag) + i - 1;
		return (1);
	}
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
		data->i += ncount(data->precision);
		if ((data->precision > data->flag && data->flag > 0) || (data->precision > data->flag * -1 && data->flag < 0))
		{
			data->filler = '0';
			data->container = get_buffer(data->precision, data);
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
