/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 11:41:30 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/23 12:30:57 by bkonjuha         ###   ########.fr       */
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
	}
	return (0);
}
