/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:20:25 by gdaouda           #+#    #+#             */
/*   Updated: 2021/07/30 21:29:43 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		i;
	int		j;
	char	c[10];

	nb = n;
	j = 0;
	if (nb == 0)
		j += ft_putchar('0');
	if (nb < 0)
	{
		j += ft_putchar('-');
		nb = -nb;
	}
	i = 0;
	while (nb > 0)
	{
		c[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	while (--i >= 0)
		j += ft_putchar(c[i]);
	return (j);
}
