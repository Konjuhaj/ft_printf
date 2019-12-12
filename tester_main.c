/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/12 18:06:49 by bkonjuha         ###   ########.fr       */
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

// ft_printf("%-10x\n", 42);
//   	ft_printf("%010x\n", 542);
// // 	printf("%010x\n", 542);

// 	ft_printf("%5%\n");
// // 	printf("%5%\n");

// 	ft_printf("%s%s%s%s%s", "this", "is", "a", "multi", "string\n");
// // 	printf("%s%s%s%s%s", "this", "is", "a", "multi", "string\n");

//   ft_printf("%d\n", 2147483649);
// //   printf("%d\n", (int)2147483649);


	ft_printf("%-5c\n", 42);
// 	printf("%-5c\n", 42);

//  	ft_printf("%010x\n", 542);
//  	// printf("%010x\n", 542);


	system("\n\nLEAKS a.out\n\n");
	return (0);
}
