/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:55:55 by gdaouda           #+#    #+#             */
/*   Updated: 2021/08/10 19:02:24 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include "includes/ft_printf.h"

int	print(char *c, int i)
{
	int			j;
	int			k;
	const char	tab[] = {"spdixXuc"};

	j = 0;
	k = 0;
	while (tab[k] != '\0')
	{
		if (tab[k] == c[i] && c[i - 1] == '%'
			&& c[i - 2] == '%' && c[i - 3] != '%')
		{
			j += ft_putchar(c[i]);
			return (j);
		}
		if (tab[k] == c[i] && c[i - 1] == '%')
			return (0);
		k++;
	}
	if (c[i] != '%')
		j += ft_putchar(c[i]);
	return (j);
}

int	ft_printf(const char *f, ...)
{
	va_list		ar;
	int			i;
	int			w;

	i = -1;
	w = 0;
	va_start(ar, f);
	while (f[++i] != '\0')
	{
		if ((f[i] == '%' && (f[i + 1] == 'd'
					|| f[i + 1] == 'i' || f[i + 1] == 'c' || f[i + 1] == 'u')))
			w += intg(va_arg(ar, int), f[i + 1]);
		if (f[i] == '%' && f[i + 1] == 's')
			w += putstr(va_arg(ar, char *));
		if ((f[i] == '%' && (f[i + 1] == 'x' || f[i + 1] == 'X')))
			w += hexa(va_arg(ar, unsigned int), f[i + 1]);
		if ((f[i] == '%' && f[i + 1] == 'p'))
			w += paddr(va_arg(ar, void *));
		w += print((char *)f, i);
		if (f[i] == '%' && f[i + 1] == '%')
			w += ft_putchar(f[i++]);
	}
	va_end(ar);
	return (w);
}
