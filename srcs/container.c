/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:24:02 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/14 08:54:34 by bkonjuha         ###   ########.fr       */
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

void	fill_container(char *c, t_data *data)
{
	size_t	start;
	size_t	destlen;
	size_t	srclen;

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
