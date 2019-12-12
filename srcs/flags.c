/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/12 16:47:29 by bkonjuha         ###   ########.fr       */
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

int		is_flag(const char *c, t_data *data)
{
	int i;

	i = 0;
	data->flag = 0;
	data->filler = *c;
	while (c[i] == ' ' || c[i] == '#' || c[i] == '0')
		i++;
	if (c[i] == '+' || c[i] == '-' || ft_isdigit(c[i]))
	{
		data->flag = ft_atoi(c + i);
		data->container = get_buffer(data->flag, data->filler == 48 ? '0' : ' ');
		data->i += data->flag < 0 ? ncount(data->flag) + i - 1: ncount(data->flag) + i - 1;
		return (1);
	}
	data->i += i;
	return (0);
}

int		is_width(const char *s, t_data *data)
{
	if (*s == '*')
	{
		data->width = *s;
		return (1);
	}
	return (0);
}

int		is_precision(const char *s, t_data *data)
{
	if (*s == '.' || *s == '*')
	{
		data->precision = *s;
		return (1);
	}
	return (0);
}

int		is_legth(const char *s, t_data *data)
{
	if ((s[0] == 'h' && s[1] == 'h') ||
			(s[0] == 'l' && s[1] == 'l'))
	{
		data->length = s[0] + s[1];
		data->i++;
		return (1);
	}
	else if (s[0] == 'h' || s[0] == 'l')
	{
		data->length = s[0];
		return (1);
	}
	return (0);
}
