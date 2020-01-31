/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2020/01/31 22:02:03 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	// ft_printf("===========MINE_STRIN===========\n");
	// ft_printf("%5s\n\n", "goes over");
	// ft_printf("%7.5s\n\n", "bombastic");
	// ft_printf("%7.7s%3.7s\n\n", "hello", "world");
	// ft_printf("%7.3s%7.7s\n\n", "hello", "world");
	// ft_printf("%.03s\n\n", NULL);

	// printf("===========REAL_STRING===========\n");
	// printf("%5s\n\n", "goes over");
	// printf("%7.5s\n\n", "bombastic");
	// printf("%7.7s%3.7s\n\n", "hello", "world");
	// printf("%7.3s%7.7s\n\n", "hello", "world");
	// printf("%.03s\n\n", NULL);

	// ft_printf("===========MINE_PRECISION===========\n");
	// ft_printf("%.03s\n\n", NULL);
	// ft_printf("%.0%\n\n");
	// ft_printf("%-.00s\n\n", NULL);

	// printf("===========MINE_PRECISION===========\n");
	// printf("%.03s\n\n", NULL);
	// printf("%.0%\n\n");
	// printf("%-.00s\n\n", NULL);

	// ft_printf("===========MINE_(i)FLAG===========\n");
	// ft_printf("mine says = %i\n\n", -1);
	// ft_printf("this %i number\n\n", -267);

	// printf("===========REAL_(i)FLAG===========\n");
	// printf("real says = %i\n\n", -1);
	// printf("this %i number\n\n", -267);

	// ft_printf("===========MINE_{PREFIX}===========\n");
	// ft_printf("%-10.5i\n\n", -216);
	// ft_printf("%10.5i\n\n", -216);
	// ft_printf("@moulitest: %.10d\n\n", -42);
	// ft_printf("%.4i\n\n", -2372);
	// ft_printf("%.3i\n\n",-23646);

	// printf("===========MINE_{PREFIX}===========\n");
	// printf("%-10.5i\n\n", -216);
	// printf("%10.5i\n\n", -216);
	// printf("@moulitest: %.10d\n\n", -42);
	// printf("%.4i\n\n", -2372);
	// printf("%.3i\n\n",-23646);

	ft_printf("%#.10x", 50);

	// system("\n\nLEAKS a.out\n\n");
	return (0);
}
