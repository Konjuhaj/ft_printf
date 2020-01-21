/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/19 17:44:35 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		create_buffer(const char *s, t_data *data)
{
	int size;

	size = data->size;
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
		if (data->precision < data->size
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
	size = data->size - prec;
	while (--size > -1 && data->container.id == NUMBER
			&& data->precision != -1 && BUFFER[size] == '0')
		BUFFER[size] = ' ';
}

void	fill_buffer(char *temp, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;
	int		precision;
	char	*c;

	c = temp;
	dot_validator(data, &c, &precision);
	destlen = ft_strlen(BUFFER);
	srclen = precision < 0 ? ft_strlen(c) : precision;
	if (srclen > destlen && data->container.id == NUMBER)
	{
		free(BUFFER);
		BUFFER = c;
	}
	else if (data->allign != '-')
	{
		start = destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(BUFFER + start, c, destlen - start);
	}
	else
		ft_memcpy(BUFFER, c, srclen);
	if (c != temp && c != BUFFER && data->container.id == NUMBER)
		free(c);
}

void	add_buffer_postfix(t_data *data, char *postfix)
{
	char *temp;

	temp = ft_strjoin(BUFFER, postfix);
	free(BUFFER);
	BUFFER = temp;
}

void	add_buffer_prefix(char *prefix, t_data *data)
{
	char *temp;

	temp = ft_strjoin(prefix, BUFFER);
	free(BUFFER);
	BUFFER = temp;
}
