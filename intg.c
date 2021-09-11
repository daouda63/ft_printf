/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intg.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:36:56 by gdaouda           #+#    #+#             */
/*   Updated: 2021/07/30 21:33:11 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	decimal(int n)
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

int	len_(unsigned int t)
{
	unsigned int	i;

	i = 0;
	if (t == 0)
		i = i + 1;
	while (t != 0)
	{
		if (t < 0)
		{
			i = 1;
			t *= -1;
		}
		t /= 10;
		i++;
	}
	return (i);
}

int	Udecimal(unsigned int n)
{
	unsigned int	long_n;

	long_n = n;
	if (long_n >= 10)
	{
		ft_putnbr(long_n / 10);
		ft_putnbr(long_n % 10);
	}
	else
	{
		ft_putchar(long_n + '0');
	}
	return (len_(long_n + 0));
}

int	intg(int n, char ct)
{
	int		i;

	i = 0;
	if (ct == 'd' || ct == 'i')
		i += decimal(n);
	if (ct == 'c')
		i += ft_putchar(n);
	if (ct == 'u')
		i += Udecimal(n);
	return (i);
}
