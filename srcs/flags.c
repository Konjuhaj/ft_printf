/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 21:43:31 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_parameter(const char *s, t_data *data)
{
	if(ft_isalnum(*s) && s[1] == '$')
	{
		data->param = ft_atoi(s);
		return (1);
	}
	return(0);
}

int		is_flag(char c, t_data *data)
{
	if (c == '+' || c == '-' || c == '#' || c == '0')
	{
		data->flag = c;
		return (1);
	}
	return (0);
}

int		is_width(char c, t_data *data)
{
	if (c == '*')
	{
		data->width = c;
		return (1);
	}
	return (0);
}

int		is_precision(char c, t_data *data)
{
	if (c == '.' || c == '*')
	{
		data->precision = c;
		return (1);
	}
	return (0);
}

int		is_legth(const char *s, t_data *data)
{
	if (s[0] == 'h' || s[0] == 'l')
	{
		data->length = s[0];
		return (1);
	}
	else if ((s[0] == 'h' && s[1] == 'h') ||
			(s[0] == 'l' && s[1] == 'l'))
	{
		data->length = s[0] + s[1];
		return (1);
	}
	return (0);
}
