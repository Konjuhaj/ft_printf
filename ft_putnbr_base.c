/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:19:11 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 14:13:49 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_base(long long num, int base)
{
	int n;

	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
	}
	if (num >= (long long)base && base != 2)
	{
		ft_putnbr_base(num / base, base);
		n = num % base >= 10 ? num % base + 'a' - 10 : num % base + 48;
		ft_putchar(n);
	}
	else if (base != 2)
	{
		n = num >= 10 ? num + 'a' - 10 : num + 48;
		ft_putchar(n);
	}
	n = 128;
	while (n > 0 && base == 2)
	{
		ft_putchar(*(num >= n ? "1" : "0"));
		num = num >= n ? num % n : num;
		n /= 2;
	}
}

int		main(int ac, char **av)
{
	char s[] = "s";
	ft_putendl((const char *)&s);
	if (ac)
		ft_putnbr_base(ft_atoi(av[1]), ft_atoi(av[2]));
	// printf("%p", s);
	return (0);
}
