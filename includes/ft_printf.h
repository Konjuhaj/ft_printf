/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/14 08:24:42 by bkonjuha         ###   ########.fr       */
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
	char		hash;
	char		filler;
	int			ret;
	int			i;
	int			param;
	char		*container;
	va_list		arg;
	int			flag;
	char		width;
	int			precision;
	int			length;
	char		type;
}				t_data;

int				ft_printf(const char *format, ...);

int				is_parameter(const char *s, t_data *data);

int				is_flag(const char *c, t_data *data);

int				is_width(const char *s, t_data *data);

int				is_precision(const char *s, t_data *data);

int				is_legth(const char *s, t_data *data);

void			ft_printhex(t_data *data, int id);

void			ft_printoct(t_data *data, int id);

void			ft_printdec(t_data *data, int id);

void			ft_printchar(t_data *data, int id);

void			ft_printstr(t_data *data, int id);

void			ft_printcent(t_data *data, int id);

char			*get_buffer(int n, int filler);

void			fill_container(char *c, t_data *data);

#endif
