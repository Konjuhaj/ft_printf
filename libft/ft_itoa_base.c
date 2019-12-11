/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:54:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/11 15:45:16 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ncount_base(long long n, int base)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (nb <= 0)
	{
		i++;
	}
	while (nb > 0 || nb < 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long nb, int base)
{
	int		i;
	char	*result;

	i = ncount_base(nb, base);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (nb == 0)
	{
		result[0] = 48;
		return (result);
	}
	if (nb < 0)
	{
		nb *= -1;
		result[0] = '-';
	}
	while (nb > 0)
	{
		result[i--] = nb % base >= 10 ? nb % base + 87 : nb % base + 48;
		nb = nb / base;
	}
	return (result);
}
