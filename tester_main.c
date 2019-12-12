/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/12 10:47:36 by bkonjuha         ###   ########.fr       */
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
	int one = 1220000;
	int two;
	int three;
	char c = 'c';


	str1 = "ONE";
	str2 = "TWO";
	str3 = "THREE";
	str4 = "FOUR";

  	// ft_printf("%010x\n", 542);
	// printf("%###000000000000000000010x\n\n", 542);

	// ft_printf("%5%\n");
	// printf("%5%\n\n");

	// ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string");
	// printf("\n%s%s%s%s%s", "this", "is", "a", "multi", "string");

//   ft_printf("%d", 2147483649);
//   printf("\n%d", (int)2147483649);


	// ft_printf("%-5c", 42);
	// printf("\n%-5c", 42);

	ft_printf("%lu", -42);
	printf("\n%lu", (unsigned long)-42);


	return (0);
}
