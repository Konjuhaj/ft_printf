/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/03 15:54:51 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	get_buffer(const char *s, t_data *data)
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
void	update_buffer(t_data *data)
{
	int size;

	size = data->container.size - data->precision;
	while(--size && data->container.id == NUMBER && data->type == 'd'
			&& data->precision != -1
			&& BUFFER[size - 1] == '0')
			BUFFER[size] = ' ';
}

char*	handle_sign(t_data *data, char *temp)
{
	int		i;
	char	sign[2];

	i = 0;
	sign[1] = '\0';
	sign[0] = temp[0] == '-' ? '-' : 0;
	if (data->sign > 0 && *sign != '-')
		sign[0] = data->sign;
	if (sign[0] && sign[0] != '-' && data->container.id == NUMBER && data->type != 'u')
	{
		if (BUFFER[0] != ' ' && (data->container.size <= data->precision
			|| data->container.size == 0))
		{
			ft_putchar(data->sign);
			data->ret++;
		}
		else if (data->container.size > data->precision && BUFFER[0] != ' '
				&& data->precision >= 0)
		 	{
				 i = ft_strlen(BUFFER) - 1;
				while(--i >= 0)
					BUFFER[i + 1] = BUFFER[i];
				BUFFER[0] = sign[0];
		 	}
		else
		{
			while(BUFFER[i] == ' ')
				i++;
			BUFFER[i == 0 ? 0 : i - 1] = data->sign;
		}
	}
	else if (temp[0] == '-' && data->container.filler == '0')
	{
		while (BUFFER[i] != '-')
			i++;
		BUFFER[i] = '0';
		if (BUFFER[0] == ' ')
		{
			while (BUFFER[i] == '0')
				i--;
			BUFFER[i] = '-';
		}
		else if (data->container.size > data->precision)
			BUFFER[0] = '-';
		else if (BUFFER[0] == '0')
			BUFFER = ft_strjoin("-", BUFFER);

	}
	return (BUFFER);
}
