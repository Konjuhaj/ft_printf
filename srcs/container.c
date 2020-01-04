/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:24:02 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/03 16:51:51 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_hash(char *s, t_data *data, size_t *start)
{
	char *temp;

	temp = "0x";
	if (BUFFER[0] == '0' && data->type != 'o')
	{
		BUFFER[1] = data->type;
		*start = 2;
	}
	else if (data->type == 'o')
	{
		temp = ft_strjoin("0", s);
		s = temp;
	}
	else
	{
		temp = ft_strjoin("0x", s);
		s = temp;
	}
	return (s);
}

char	*handle_prsecision(char *c, t_data *data)
{
	char *temp;
	int len;
	int padding;

	len = ft_strlen(c);
	padding = data->precision - len;
	if(!(temp = (char *)malloc(sizeof(char) * (data->precision + 1))))
		return (NULL);
	data->container.filler = '0';
	ft_memset(temp, data->container.filler, data->precision);
	ft_strncpy(temp + padding, c, len);
	return (temp);
}

void	fill_container(char *c, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;
	int precision;
	int remove;

	remove = 0;
	precision = data->precision;
	if (data->hash == '#')
		c = handle_hash(c, data, &start);
	if (data->container.id == NUMBER)
		precision = data->precision < (int)ft_strlen(c) ?
		(int)ft_strlen(c) : data->precision;
	else if (data->container.id == TEXT)
		precision = data->precision < (int)ft_strlen(c) ?
		data->precision : (int)ft_strlen(c);
	if (data->precision > (int)ft_strlen(c) && ft_strlen(c) != 0
		&& data->container.id == NUMBER)
	{
		c = handle_prsecision(c, data);
		remove = 1;
	}
	destlen = ft_strlen(BUFFER);
	srclen = precision < 0 ? ft_strlen(c) : precision;
	srclen = ft_strlen(c) == 0 ? 0 : srclen;
	start = 0;
	if (data->size > 0)
	{
		start += destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(BUFFER + start, c, destlen - start);
	}
	else
		ft_strncpy(BUFFER + start, c, srclen);
	if (remove == 1)
		free(c);

}
