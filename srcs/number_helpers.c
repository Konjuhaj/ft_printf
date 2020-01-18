/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 06:35:00 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/18 22:06:44 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	append_temp_to_buffer(t_data *data, char *temp)
{
	int free_temp_if_precision_and_sign;

	free_temp_if_precision_and_sign = 0;
	if (BUFFER)
		free(BUFFER);
	BUFFER = data->hash == '#' ?  hash_flag(temp, data) : temp;
	if (data->precision > (int)ft_strlen(BUFFER))
	{
		BUFFER = dot_flag(temp, data);
		free_temp_if_precision_and_sign++;
	}
	if(data->sign == ' ' || data->sign == '+' || free_temp_if_precision_and_sign == 1)
		sign_flag(data, temp);
	data->ret += ft_strlen(BUFFER);

}

static void	output_nothing(t_data *data, char *temp)
{
	data->ret += BUFFER == NULL ? 0 : ft_strlen(BUFFER);
	if (data->sign == '+')
		sign_flag(data, temp);
	ft_strdel(&temp);
}

void	number_hub(t_data *data, char *temp)
{
	if(temp[0] == '-')
		data->sign = '-';
	if (data->hash == '#')
		temp = hash_flag(temp, data);
	if (data->precision == 0 && temp[0] == '0' && data->type != 'f')
		output_nothing(data, temp);
	else
	{
		if (!(BUFFER) || data->container.size <= (int)ft_strlen(temp))
			append_temp_to_buffer(data, temp);
		else
			ft_fill(temp, data);
		if (data->type == 'X')
			ft_capitalize(BUFFER);
	}
}
