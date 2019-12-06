/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 10:25:42 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_parameter(const char *s, va_list *args, t_data *data)
{
	int i;
	va_list copy;

	i = 1;
	va_copy(copy, *args);
	if(ft_isalnum(*s) && s[i] == '$')
	{
		i = ft_atoi(s);
		while (--i)
		{
			va_arg(copy, char*);
		}
		data->arg = &copy;
		return (1);
	}
	return(0);
}

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		is_width(char c)
{
	if (c == '*')
		return (1);
	return (0);
}

int		is_precision(char c)
{
	if (c == '.' || c == '*')
		return (1);
	return (0);
}

int		is_legth(const char *s)
{
	int i;

	i = 0;
	if (s[i] == 'h' || (s[i] == 'h' && s[i + 1] == 'h') ||
		s[i] == 'l' || (s[i] == 'l' && s[i + 1] == 'l') ||
		s[i] == 'L' || s[i] == 'z' || s[i] == 'j' || s[i] == 't')
		return (1);
	return (0);
}
