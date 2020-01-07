/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/07 14:57:44 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_buffer(const char *s, t_data *data)
{
	int size;

	size = data->container.size;
	if (size > 0 && s)
	{
		if (data->precision > size && data->container.id == NUMBER)
		{
			size = data->precision;
			data->container.filler = '0';
		}
		BUFFER = (char *)malloc(sizeof(char) * size + 1);
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

void	handle_minus(t_data *data, char sign)
{
	int i;
	int slen;
	int space;

	space = data->container.size;
	slen = ft_strlen(BUFFER);
	i = 0;
	while (BUFFER[i] != '-')
		i++;
	BUFFER[i] = '0';
	if (BUFFER[0] == ' ')
	{
		i = 0;
		while (!ft_isalnum(BUFFER[i]))
			i++;
		BUFFER[i - 1] = '-';
	}
	else if (data->allign == '-' && data->precision < space)
		move_right(data, sign);
	else if ((BUFFER[0] != '0' && data->precision >= 0)
			|| slen > data->precision
			|| data->precision == -1)
		BUFFER[0] = '-';
	else if (BUFFER[0] == '0')
		BUFFER = ft_strjoin("-", BUFFER);
}

void	handle_plus(t_data *data, char sign, int len)
{
	int		space;
	int		i;

	space = data->container.size;
	i = 0;
	if (BUFFER[0] != ' ' && (space <= data->precision
			|| space == 0 || space <= len))
	{
		ft_putchar(data->sign);
		data->ret++;
	}
	else if (data->allign == '-')
		move_right(data, sign);
	else
	{
		while (BUFFER[i] == ' ')
			i++;
		BUFFER[i == 0 ? 0 : i - 1] = data->sign;
	}
}

char	*handle_sign(t_data *data, char *temp)
{
	char	sign;
	int		len;

	len = ft_strlen(temp);
	sign = temp[0] == '-' ? '-' : 0;
	BUFFER = BUFFER == NULL ? ft_strnew(1) : BUFFER;
	if (data->sign > 0 && sign != '-')
		sign = data->sign;
	if (sign && sign != '-' && data->container.id == NUMBER
		&& data->type != 'u')
		handle_plus(data, sign, len);
	else if (temp[0] == '-' && data->container.filler == '0')
		handle_minus(data, sign);
	return (BUFFER);
}
