/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:24:02 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/17 17:15:21 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_buffer(int n, int filler)
{
	char *buffer;

	if (n < 0)
		n *= -1;
	buffer = (char *)malloc(sizeof(char) * n + 1);
	ft_memset(buffer, filler, n);
	return (buffer);
}

char	*handle_hash(char *s, t_data *data, size_t *start)
{
	char *temp;

	temp = "0x";
	if (data->container[0] == '0' && data->type != 'o')
	{
		data->container[1] = data->type;
		*start = 2;
	}
	else if (data->type == 'o')
	{
		temp = ft_strjoin("0", s);
		// free(s);
		s = temp;
	}
	else
	{
		temp = ft_strjoin("0x", s);
		// free(s);
		s = temp;
	}
	return (s);
}

void	fill_container(char *c, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;


	if (data->hash == '#')
		c = handle_hash(c, data, &start);
	destlen = ft_strlen(data->container);
	srclen = ft_strlen(c);
	start = 0;
	if (data->flag > 0)
	{
		start += destlen - srclen > 0 ? destlen - srclen : 0;
		ft_strncpy(data->container + start, c, destlen - start);
	}
	else
		ft_strncpy(data->container + start, c, srclen);
}
