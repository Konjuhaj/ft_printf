/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:37:05 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/14 16:31:35 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_default(t_data *data, int i)
{
	ft_putchar('%');
	data->ret++;
	return (i);
}

void	s_flag(t_data *data, int id)
{
	char	*s;
	int		slen;
	int		size;

	s = va_arg(data->arg, char *);
	if (id)
	{
		size = data->container.size;
		if (!s)
			s = "(null)";
		slen = ft_strlen(s);
		slen = data->precision > slen ? ft_strlen(s) : data->precision;
		slen = slen == -1 ? ft_strlen(s) : slen;
		if ((!(BUFFER) && id) || size < slen
		|| ((data->precision > slen && slen != 0) && size < slen))
		{
			if (BUFFER)
				free(BUFFER);
			BUFFER = data->precision > -1 ?
			ft_strsub(s, 0, data->precision) : ft_strdup(s);
		}
		else
			fill_buffer(s, data);
		data->ret += ft_strlen(BUFFER);
	}
}

void	c_flag(t_data *data, int id)
{
	char *c;

	c = ft_strnew(2);
	c[0] = va_arg(data->arg, int);
	c[1] = '\0';
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
			BUFFER[data->allign == '-' ? 0 : data->size - 1] = '\0';
			data->ret++;
		}
		else
			ft_fill(c, data);
	}
	free(c);
	data->ret += ft_strlen(BUFFER);
}

void	percent_flag(t_data *data, int id)
{
	if (!(BUFFER) && id)
		BUFFER = ft_strdup("%");
	else
		fill_buffer("%", data);
	data->ret += ft_strlen(BUFFER);
}
