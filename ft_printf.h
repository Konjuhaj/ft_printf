/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 10:24:10 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define OCTAL 8
# define HEXAL 16
# define DECIMAL 10
# define BINARY 2
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct	s_data
{
	int			i;
	char		*container;
	char		type;
	va_list		*arg;
}				t_data;

int				is_parameter(const char *s, va_list *args, t_data *data);

int				is_flag(char c);

int				is_width(char c);

int				is_precision(char c);

int				is_legth(const char *s);


#endif
