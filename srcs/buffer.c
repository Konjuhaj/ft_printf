/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/14 16:46:18 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		create_buffer(const char *s, t_data *data)
{
	int size;

	size = data->container.size;
	data->container.filler = data->container.id == TEXT ? ' '
	: data->container.filler;
	if (size > 0 && s)
	{
		if (data->precision > size && data->container.id == NUMBER)
		{
			size = data->precision;
			data->container.filler = '0';
		}
		BUFFER = ft_strnew(size + 1);
		ft_memset(BUFFER, data->container.filler, size);
		if (data->precision < data->container.size
			&& data->container.id == NUMBER && data->type == 'd'
			&& data->precision != -1 && data->container.filler == '0')
		{
			size = size - data->precision;
			while (--size >= 0)
				BUFFER[size] = ' ';
		}
	}
	return (0);
}

void	update_buffer(t_data *data, char *temp)
{
	int size;
	int prec;

	if (data->allign == '-')
		return ;
	prec = data->precision > (int)ft_strlen(temp) ?
			data->precision : (int)ft_strlen(temp);
	size = data->container.size - prec;
	while (--size > -1 && data->container.id == NUMBER
			&& data->precision != -1 && BUFFER[size] == '0')
		BUFFER[size] = ' ';
}

void	fill_buffer(char *c, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;
	int		precision;
	int		remove;

	remove = 0;
	start = 0;
	precision = data->precision;
	dot_validator(data, &c, &precision, &remove);
	destlen = ft_strlen(BUFFER);
	srclen = precision < 0 ? ft_strlen(c) : precision;
	srclen = ft_strlen(c) == 0 ? 0 : srclen;
	if (srclen > destlen && data->container.id == NUMBER)
	{
		free(BUFFER);
		BUFFER = ft_strdup(c);
	}
	else if (data->allign != '-')
	{
		start += destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(BUFFER + start, c, destlen - start);
	}
	else
		ft_memcpy(BUFFER + start, c, srclen);
	if (remove == 1)
		free(c);
}
