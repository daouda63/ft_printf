/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaouda <gdaouda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:59:50 by gdaouda           #+#    #+#             */
/*   Updated: 2021/07/30 21:35:10 by gdaouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define  FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		putstr(char *s);
int		ft_putnbr(int n);
int		ft_printf(const char *f, ...);
int		intg(int nb, char ct);
int		hexa(unsigned int nb, char c);
int		paddr(void *n);
void	putnbrU(unsigned int n);

#endif
