/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:49:22 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 18:49:28 by bkonjuha         ###   ########.fr       */
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
	data->flag = 0;
	if (*c == '+' || *c == '-' || *c == '#' || ft_isdigit(*c))
	{
		data->flag = ft_atoi(c);
		data->i += data->flag < 0 ? ncount(data->flag) : ncount(data->flag) - 1;
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
