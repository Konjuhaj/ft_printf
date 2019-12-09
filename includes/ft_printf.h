/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/08 23:18:50 by bkonjuha         ###   ########.fr       */
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
# include "../libft/libft.h"

typedef	struct	s_data
{
	int			i;
	int			param;
	char		*container;
	va_list		arg;
	char		flag;
	char		width;
	int			precision;
	int			length;
	char		type;
}				t_data;

void			ft_printf(const char *format, ...);

int				is_parameter(const char *s, t_data *data);

int				is_flag(char s, t_data *data);

int				is_width(char c, t_data *data);

int				is_precision(char c, t_data *data);

int				is_legth(const char *s, t_data *data);

void			ft_printnum(t_data *data, int id);

void			ft_putnbr_base(long long num, int base);

void			ft_printchar(t_data *data, int id);

void			ft_printstr(t_data *data, int id);

#endif
