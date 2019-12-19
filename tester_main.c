/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/18 15:48:44 by bkonjuha         ###   ########.fr       */
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

  ft_printf("%5.2x", 5427);
//   printf("\n");
// 	system("\n\nLEAKS a.out\n\n");
	return (0);
}
