/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:53:35 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/09 16:29:53 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

double	round_up(double num, int prec)
{
	double	i;
	int		n;

	n = prec;
	i = 5.0;
	if (num == 2147483648.000000 || num == -2147483648.000000)
		return (num);
	while (n--)
		i /= 10.0;
	return (num = num < 0.0000000000 ? num - i : num + i);
}

char	*ft_f_itoa(double num, int prec)
{
	int			count;
	long long	mover;
	int			i;
	char		*temp;

	mover = 10;
	count = ncount(num);
	i = count + 1;
	prec = prec == -1 ? 6 : prec;
	num = round_up(num, prec + 1);
	temp = ft_strnew(prec + 1 + count);
	temp = ft_memcpy(temp, ft_itoa(num), count);
	temp[count] = prec == 0 ? 0 : '.';
	if (num < 0.0 && temp[0] != '-')
		ft_putchar('-');
	num = num < 0.0000000000 ? num * -1.0 : num;
	while (i < prec + count + 1)
	{
		temp[i++] = (long long)(num * mover) % 10 + '0';
		mover *= 10;
	}
	return (temp);
}

long double	l_round_up(long double num, int prec)
{
	long double	i;
	int			n;

	n = prec;
	i = 5.0;
	while (n--)
		i /= 10.0;
	return (num = num < 0.0000000000 ? num - i : num + i);
}

char	*ft_lf_itoa(long double num, int prec)
{
	int			count;
	long long	mover;
	int			i;
	char		*temp;

	mover = 10;
	count = ncount(num);
	i = count + 1;
	prec = prec == -1 ? 6 : prec;
	num = round_up(num, prec + 1);
	temp = ft_strnew(prec + 1 + count);
	temp = ft_memcpy(temp, ft_itoa(num), count);
	temp[count] = prec == 0 ? 0 : '.';
	if (num < 0.0 && temp[0] != '-')
		ft_putchar('-');
	num = num < 0.0000000000 ? num * -1. : num;
	while (i < prec + count + 1)
	{
		temp[i++] = (long long)(num * mover) % 10 + '0';
		mover *= 10;
	}
	return (temp);
}
