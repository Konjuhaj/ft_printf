/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 10:54:06 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/27 12:09:27 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ncount(int n)
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
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	long	nb;

	nb = n;
	i = ncount(n);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	result[i--] = '\0';
	if (n == 0)
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
		result[i--] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (result);
}
