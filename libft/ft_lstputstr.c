/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:20:25 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/10/31 08:54:02 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputstr(t_list *lst)
{
	while (lst)
	{
		ft_putstr((char *)lst->content);
		write(1, "->", 2);
		lst = lst->next;
	}
}
