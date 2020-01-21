/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 06:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/19 17:44:35 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	append_str_to_buffer(t_data *data, char *temp)
{
	if (BUFFER)
		free(BUFFER);
	BUFFER = data->hash == '#' ? hash_flag(temp, data) : temp;
	if (data->precision > (int)ft_strlen(BUFFER))
		BUFFER = dot_flag(temp, data);
	if (data->sign != 0 || (temp[0] == '-' && BUFFER[0] == '0'))
		BUFFER = sign_flag(data, temp);
	if (BUFFER != temp)
		free(temp);
}

static void	zero_precision_w_zero_num(t_data *data, char *temp)
{
	if (data->hash == '#' && data->type == 'o')
		BUFFER = ft_strdup("0");
	data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
	if (data->sign == '+')
		BUFFER = sign_flag(data, temp);
	free(temp);
}

void		number_hub(t_data *data, char *temp)
{
	if (temp[0] == '0' && data->precision == 0)
		zero_precision_w_zero_num(data, temp);
	else
	{
		if (!(BUFFER) || data->size <= (int)ft_strlen(temp))
			append_str_to_buffer(data, temp);
		else
			ft_fill(temp, data);
		if (data->type == 'X')
			ft_capitalize(BUFFER);
		data->ret += ft_strlen(BUFFER);
	}
}
