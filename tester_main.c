/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/09 14:16:05 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	int one = 1220;
	int two;
	int three;
	char c = 'c';


	str1 = "ONE";
	str2 = "TWO";
	str3 = "THREE";
	str4 = "FOUR";

	// ft_printf("int value is %d, hex value is [%x], and octal value is %o\n", one, one, one);
	ft_printf("int value is %hhi, hex value is %x, and octal value is %x\n", (char)one, one, (int)str1);
	printf("int value is %hhi, hex value is %x, and octal value is %x\n", (char)one, one, (int)str1);
	// ft_printf("%4$s, bthis %1$s, get %1$s, also get%2$s this %3$s\n", str1, str2, str3, str4);
	return (0);
}
