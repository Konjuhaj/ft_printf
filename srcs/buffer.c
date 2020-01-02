/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/02 16:12:13 by bkonjuha         ###   ########.fr       */
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
