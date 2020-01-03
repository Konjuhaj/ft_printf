/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:37:05 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/03 10:12:00 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printaddr(t_data *data, int id)
{
	unsigned long	num;
	char			*temp;

	num = va_arg(data->arg, unsigned long);
	temp = ft_strjoin("0x", ft_uitoa_base(num, HEXAL));
	if (!(BUFFER) || data->container.size < (int)ft_strlen(temp))
	{
		BUFFER = temp;
	}
	else if (id)
		ft_fill(temp, data);
}

int		ft_default(t_data *data, int i)
{
	ft_putchar('%');
	data->ret++;
	return (i);
}
