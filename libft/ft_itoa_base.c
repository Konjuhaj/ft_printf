/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:54:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/17 19:01:16 by bkonjuha         ###   ########.fr       */
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
	int				i;
	int				num;
	char			*result;

	i = ncount_base(nb, base);
	if (nb == -9223372036854775807 - 1)
		i = 20;
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (nb == 0)
		result[0] = 48;
	if (nb < 0)
		result[0] = '-';
	while (nb != 0)
	{
		num = nb % base < 0 ? nb % base * -1 : nb % base;
		result[i--] = num >= 10 ? num + 87 : num + 48;
		nb = nb / base;
	}
	return (result);
}
