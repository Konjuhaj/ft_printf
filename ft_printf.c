/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 09:33:51 by bkonjuha         ###   ########.fr       */
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

char	get_type(const char *s, int i)
{
	while (s[i] != 'd' && s[i] != 'i' && s[i] != 'u' && s[i] != 'f' &&
			s[i] != 'F' && s[i] != 'e' && s[i] != 'E' && s[i] != 'g' &&
			s[i] != 'G' && s[i] != 'x' && s[i] != 'X' && s[i] != 'o' &&
			s[i] != 's' && s[i] != 'c' && s[i] != 'p' && s[i] != 'a' &&
			s[i] != 'A' && s[i] != 'n')
			i++;
	return (s[i]);
}

int		get_container(const char *src, int i, va_list *arg)
{
	t_data data;

	data.i = i + 1;
	data.type = get_type(src, i);
	while(is_parameter(src + data.i, arg, &data))
		data.i += 2;
	while (is_flag(src[data.i]))
		data.i++;
	while (is_width(src[data.i]))
		data.i++;
	while (is_precision(src[data.i]))
		data.i++;
	while (is_legth(src))
		data.i++;
	data.container = (char *)malloc(sizeof(char) * (data.i + 1 - i));
	ft_strncpy(data.container, src + i, (size_t)data.i - i);
	ft_putendl(data.container);
	return (data.i);
}

void	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = -1;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
			i = get_container(str, i, &args);
		// ft_putchar(str[i]);
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
	// printf("%4$s, bthis %1$s, get %1$s, also get%2$s this %3$s", str1, str2, str3, str4);
	return (0);
}
