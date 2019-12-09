/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:42:39 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 18:48:33 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ncount(int n)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (nb == 0)
	{
		i++;
	}
	while (nb > 0 || nb < 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_printflag(t_data *data)
{
	if (data->flag < 0)
		data->flag *= -1;
	data->ret += data->flag - 1;
	while (--data->flag)
		ft_putchar(' ');
}
