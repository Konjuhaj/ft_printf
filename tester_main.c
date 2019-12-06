/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/06 21:45:19 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = "ONE";
	str2 = "TWO";
	str3 = "THREE";
	str4 = "FOUR";

	ft_putaddr(str2);
	printf("\n%p", str2);
	// ft_printf("%4$s, bthis %1$s, get %1$s, also get%2$s this %3$s\n", str1, str2, str3, str4);
	// printf("%4$sr, bthis %1$s, get %1$s, also get%2$s this %3$s\n", str1, str2, str3, str4);
	return (0);
}
