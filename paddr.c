/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 20:06:19 by gdaouda           #+#    #+#             */
/*   Updated: 2021/08/05 16:17:53 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	paddress(void *n)
{
	unsigned long	nb;
	unsigned int	t[100];
	int				j;
	int				i;

	nb = (unsigned long)n;
	j = 0;
	i = 0;
	while (nb >= 16)
	{
		t[j++] = nb % 16;
		nb = nb / 16;
	}
	if (nb >= 10 && nb <= 15)
		i += ft_putchar('a' + (nb - 10));
	if (!(nb >= 10 && nb <= 15))
		i += ft_putnbr(nb);
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
			i += ft_putnbr(t[j]);
		if (t[j] >= 10 && t[j] <= 15)
			i += ft_putchar('a' + (t[j] - 10));
	}
	return (i);
}

int	paddr(void *n)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += paddress(n);
	return (i);
}
