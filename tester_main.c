/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkonjuha <bkonjuha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:21:36 by bkonjuha          #+#    #+#             */
/*   Updated: 2019/12/20 16:05:26 by bkonjuha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
// 	ft_printf("RETURN----%d\n", ft_printf("MINE---- 1 %d chiffre 2 %d\n", 42, -42));
// 	printf("\nRETURN----%d\n\n", printf("\nREAL---- 1 %d chiffre 2 %d\n", 42, -42));

	// ft_printf("RETURN---%d\n", ft_printf("MINE---- 1 (%   d) chiffre 2 (% d)\n", 42, -42));
	// printf("RETURN---%d\n", ft_printf("REAL---- 1 (%   d) chiffre 2 (% d)\n", 42, -42));

	// ft_printf("RET%d\n", ft_printf("MMMMM 1 (%-12d) chiffre 2 (%-12d)\n", 42, -42));
	// printf("RET%d\n", printf("RRRRR 1 (%-12d) chiffre 2 (%-12d)\n", 42, -42));

	// ft_printf("RET%d\n", ft_printf("MMM 1 (%0d) chiffre 2 (%0d)\n", 42, -42));
	// printf("RET%d\n", printf("\nRRR 1 (%0d) chiffre 2 (%0d)\n\n", 42, -42));

	// ft_printf("%d\n", ft_printf("MMM 1 (%012d) chiffre 2 (%012d)\n", 42, -42));
	// printf("%d\n", printf("RRR 1 (%012d) chiffre 2 (%012d)\n\n", 42, -42));

	// ft_printf("%d\n", ft_printf("7chiffre 1 %-012d chiffre 2 %012d\n", 42, -42));
	// printf("%d\n\n", printf("7chiffre 1 %-012d chiffre 2 %012d\n\n", 42, -42));

	// ft_printf("%d\n", ft_printf("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
	// printf("%d\n\n", printf("8chiffre 1 %*d chiffre 2 %*d\n\n", 42, 6, 6, 6));

	// ft_printf("%d\n", ft_printf("9chiffre 1 %+d chiffre 2 %+d\n", 42, 6, -42, 6));
	// printf("%d\n\n", printf("9chiffre 1 %+d chiffre 2 %+d\n\n", 42, 6, -42, 6));

	// ft_printf("%d\n", ft_printf("10chiffre 1 (%+12d) chiffre 2 (%+12d)\n", 42, 6, -42, 6));
	// printf("%d\n\n", printf("10chiffre 1 (%+12d) chiffre 2 (%+12d)\n\n", 42, 6, -42, 6));

	// ft_printf("%d\n", ft_printf("11chiffre 1 %*12d chiffre 2 %*12d\n", 42, -6, 42, 6));
	// printf("%d\n\n", printf("11chiffre 1 %*12d chiffre 2 %*12d\n\n", 42, -6, 42, 6));

	// ft_printf("%d\n", ft_printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n", 42, -42));
	// printf("%d\n\n", printf("12chiffre 1 %-+5d chiffre 2 %-+5d\n\n", 42, -42));

	// ft_printf("%d\n", ft_printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n", 42, -42));
	// printf("%d\n\n", printf("13chiffre 1 %-+05d chiffre 2 %-+05d\n\n", 42, -42));

	// ft_printf("%d\n", ft_printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n", 42, -42));
	// printf("%d\n\n", printf("14chiffre 1 %+-5d chiffre 2 %+-5d\n\n", 42, -42));

	int i = ft_printf("%.2s is a string", "this");
	printf("\n");
	int j = printf("%.2s is a string", "this");
	printf("\n");
	printf("mine%d    real%d", i, j);

	// system("\n\nLEAKS a.out\n\n");
	return (0);
}
