/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:41:13 by gdaouda           #+#    #+#             */
/*   Updated: 2021/08/05 16:26:38 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	maj(unsigned long long nb)
{
	unsigned int	t[10];
	int				j;
	int				i;

	j = 0;
	i = 0;
	while (nb >= 16)
	{
		t[j++] = nb % 16;
		nb = nb / 16;
	}
	if (nb >= 10 && nb <= 15)
		i += ft_putchar('A' + (nb - 10));
	else
		i += ft_putnbr(nb);
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
			i += ft_putnbr(t[j]);
		else
			i += ft_putchar('A' + (t[j] - 10));
	}
	return (i);
}

int	mini(unsigned long long nb)
{
	unsigned int	t[10];
	int				j;
	int				i;

	j = 0;
	i = 0;
	while (nb >= 16)
	{
		t[j++] = nb % 16;
		nb = nb / 16;
	}
	if (nb >= 10 && nb <= 15)
		i += ft_putchar('a' + (nb - 10));
	else
		i += ft_putnbr(nb);
	while (j-- != 0)
	{
		if (!(t[j] >= 10 && t[j] <= 15))
			i += ft_putnbr(t[j]);
		else
			i += ft_putchar('a' + (t[j] - 10));
	}
	return (i);
}

int	hexa(unsigned int nb, char c)
{
	int	i;

	i = 0;
	if (c == 'X')
		i += maj(nb);
	else
		i += mini(nb);
	return (i);
}
