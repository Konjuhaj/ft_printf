/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:24:02 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/21 17:32:31 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*hash_flag(char *s, t_data *data)
{
	char *temp;

	temp = NULL;
	if (s[0] == '0')
		return (s);
	else if (data->container.filler == '0')
		BUFFER[1] = data->type;
	else if (data->type == 'x' || data->type == 'X')
		temp = ft_strjoin("0x", s);
	else if (data->type == 'o')
		temp = ft_strjoin("0", s);
	return (temp == NULL ? s : temp);
}

char	*dot_flag(char *c, t_data *data)
{
	char	*temp;
	int		len;
	int		padding;

	len = ft_strlen(c);
	padding = data->precision - len;
	temp = ft_strnew(data->precision + 1);
	data->container.filler = '0';
	ft_memset(temp, data->container.filler, data->precision);
	ft_strncpy(temp + padding, c, len);
	return (temp);
}

void	minus_flag(t_data *data, char sign)
{
	int i;
	int slen;
	int space;

	space = data->size;
	slen = ft_strlen(BUFFER);
	i = 0;
	while (BUFFER[i] != '-' && BUFFER[i])
		i++;
	BUFFER[i] = '0';
	if (BUFFER[0] == ' ')
	{
		i = 0;
		while (!ft_isalnum(BUFFER[i]))
			i++;
		BUFFER[i - 1] = '-';
	}
	else if (data->allign == '-' && data->precision < space)
		move_right(data, sign);
	else if ((BUFFER[0] != '0' && data->precision >= 0)
			|| slen > data->precision
			|| data->precision == -1)
		BUFFER[0] = '-';
	else if (BUFFER[0] == '0')
		add_buffer_prefix("-", data);
}

void	plus_flag(t_data *data, char sign, int len)
{
	int		space;
	int		i;

	space = data->size;
	i = 0;
	if (BUFFER[0] != ' ' && (space <= data->precision
			|| space == 0 || space <= len))
	{
		ft_putchar(data->sign);
		data->ret++;
	}
	else if (data->allign == '-')
		move_right(data, sign);
	else
	{
		while (BUFFER[i] == ' ')
			i++;
		BUFFER[i == 0 ? 0 : i - 1] = data->sign;
	}
}

char	*sign_flag(t_data *data, char *temp)
{
	char	sign;
	int		len;
	int		size;

	len = ft_strlen(temp);
	size = data->precision;
	sign = temp[0] == '-' ? '-' : 0;
	BUFFER = BUFFER == NULL ? ft_strnew(1) : BUFFER;
	if (data->sign > 0 && sign != '-')
		sign = data->sign;
	if (sign && sign != '-' && data->container.id == NUMBER
		&& data->type != 'u')
		plus_flag(data, sign, len);
	else if (temp[0] == '-' && data->container.filler == '0'
			&& (size >= len || size == -1))
		minus_flag(data, sign);
	return (BUFFER);
}
