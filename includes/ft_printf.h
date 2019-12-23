/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/23 12:19:38 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define OCTAL 8
# define HEXAL 16
# define DECIMAL 10
# define BINARY 2
# define NUMBER 1
# define TEXT 2
#	define BUFFER data->container.buffer
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_container
{
	int			size;
	char		*buffer;
	int			id;
	char		filler;
	char		prefix;
}				t_container;


typedef	struct	s_data
{
	char		hash;
	int			c_width;
	int			ret;
	int			i;
	int			param;
	t_container container;
	va_list		arg;
	int			size;
	char		width;
	int			precision;
	int			length;
	char		sign;
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

void			fill_container(char *c, t_data *data);

char			*handle_prsecision(char *c, t_data *data);

char			*handle_sign(char *s);

int				get_buffer(const char *s, t_data *data);


#endif
