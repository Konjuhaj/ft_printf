/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 21:43:32 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

int		is_type(char s, t_data *data)
{
	if (s == 'd' || s == 'i' || s == 'u' || s == 'f' ||
			s == 'x' || s == 'X' || s == 'o' ||
			s == 's' || s == 'c' || s == 'p')
	{
		data->type = s;
		return (1);
	}
	return (0);
}

int		get_container(const char *src, int i)
{
	t_data data;

	data.i = i + 1;
	if (is_parameter(src + data.i, &data))
		data.i += 2;
	if (is_flag(src[data.i], &data))
		data.i++;
	if (is_width(src[data.i], &data))
		data.i++;
	if (is_precision(src[data.i], &data))
		data.i++;
	if (is_legth(src, &data))
		data.i++;
	if (is_type(src[data.i], &data))
		data.i++;
	if (!(data.container = (char *)malloc(sizeof(char) * (data.i - i + 1))))
		return (0);
	ft_strncpy(data.container, src + i, data.i - i + 1);
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
			i = get_container(str, i);
	}
	va_end(args);
}
