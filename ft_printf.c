/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/03 17:24:12 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	parameter(int num, va_list args)
{
	va_list args2;

	va_copy(args2, args);
	while (--num)
	{
		va_arg(args2, char*);
	}
	ft_putstr(va_arg(args2, char*));
	va_end(args2);
}

void	ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_isalnum(*str) == 1 && str[1] == '$')
			{
				parameter((int)*str - 48, args);
				str += 3;
			}
		}
		ft_putchar(*str);
		str++;
	}
	va_end(args);
}

int		main(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = "ONE";
	str2 = "TWO";
	str3 = "THREE";
	str4 = "FOUR";

	ft_printf("%4$s, bthis %1$s, get %1$s, also get%2$s this %3$s\n", str1, str2, str3, str4);
	printf("%4$s, bthis %1$s, get %1$s, also get%2$s this %3$s", str1, str2, str3, str4);
	return (0);
}
