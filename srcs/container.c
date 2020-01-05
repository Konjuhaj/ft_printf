/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:24:02 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/04 19:13:15 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_hash(char *s, t_data *data)
{
	char *temp;

	temp = "0x";
	if (BUFFER[0] == '0' && data->type != 'o')
		BUFFER[1] = data->type;
	else if (data->type == 'o' && s[0] != '0')
	{
		temp = ft_strjoin("0", s);
		s = temp;
	}
	else if (s[0] != '0')
	{
		temp = ft_strjoin("0x", s);
		s = temp;
	}
	return (s);
}

char	*handle_prsecision(char *c, t_data *data)
{
	char	*temp;
	int		len;
	int		padding;

	len = ft_strlen(c);
	padding = data->precision - len;
	if (!(temp = (char *)malloc(sizeof(char) * (data->precision + 1))))
		return (NULL);
	data->container.filler = '0';
	ft_memset(temp, data->container.filler, data->precision);
	ft_strncpy(temp + padding, c, len);
	return (temp);
}

void	check_precision(t_data *data, char **c, int *prec, int *rem)
{
	if (data->hash == '#')
		*c = handle_hash(*c, data);
	if (data->container.id == NUMBER)
		*prec = data->precision < (int)ft_strlen(*c) ?
		(int)ft_strlen(*c) : data->precision;
	else if (data->container.id == TEXT)
		*prec = data->precision < (int)ft_strlen(*c) ?
		data->precision : (int)ft_strlen(*c);
	if (data->precision > (int)ft_strlen(*c) && ft_strlen(*c) != 0
		&& data->container.id == NUMBER)
	{
		*c = handle_prsecision(*c, data);
		*rem = 1;
	}
}

void	fill_container(char *c, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;
	int		precision;
	int		remove;

	remove = 0;
	start = 0;
	precision = data->precision;
	check_precision(data, &c, &precision, &remove);
	destlen = ft_strlen(BUFFER);
	srclen = precision < 0 ? ft_strlen(c) : precision;
	srclen = ft_strlen(c) == 0 ? 0 : srclen;
	if (data->size > 0)
	{
		start += destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(BUFFER + start, c, destlen - start);
	}
	else
		ft_memcpy(BUFFER + start, c, srclen);
	if (remove == 1)
		free(c);
}
