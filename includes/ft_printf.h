/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:27:21 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/14 16:18:54 by bkonjuha         ###   ########.fr       */
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
# define BUFFER data->container.buffer
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
	int			allign;
}				t_data;

int				ft_printf(const char *format, ...);

int				is_parameter(const char *s, t_data *data);

int				is_flag(const char *c, t_data *data);

int				is_width(const char *s, t_data *data);

int				is_precision(const char *s, t_data *data);

int				is_legth(const char *s, t_data *data);

void			x_flag(t_data *data, int id);

void			o_flag(t_data *data, int id);

void			d_flag(t_data *data, int id);

void			c_flag(t_data *data, int id);

void			s_flag(t_data *data, int id);

void			percent_flag(t_data *data, int id);

void			fill_buffer(char *c, t_data *data);

char			*dot_flag(char *c, t_data *data);

char			*sign_flag(t_data *data, char *temp);

int				create_buffer(const char *s, t_data *data);

void			update_buffer(t_data *data, char *temp);

void			ft_fill(char *temp, t_data *data);

void			p_flag(t_data *data, int id);

char			*sign_flag(t_data *data, char *temp);

int				ft_default(t_data *datas, int i);

void			typecast(t_data *data, long long *num, int id);

void			u_typecast(t_data *data, unsigned long *bignum);

void			f_flag(t_data *data, int id);

void			move_right(t_data *data, char sign);

double			round_up(double num, int prec);

long double		l_round_up(long double num, int prec);

char			*ft_f_itoa(double num, int prec);

char			*ft_lf_itoa(long double num, int prec);

void			dot_validator(t_data *data, char **c, int *prec, int *rem);

char			*hash_flag(char *s, t_data *data);


#endif
