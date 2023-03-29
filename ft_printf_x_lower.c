/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_X_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:01:12 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 21:16:15 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_precision(t_print *tab, char *j, size_t i);
void	ft_right_cs_x(t_print *tab, char *a);
void	ft_tabs_precisions(t_print *tab, char *j, size_t i);

static int	ft_size(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_printf_x_lower(t_print *tab, int digit, unsigned int a)
{
	char	*hex_digits;
	int		k;
	size_t	i;
	char	*j;

	i = 0;
	k = ft_size(a);
	hex_digits = "0123456789abcdef";
	j = (char *)malloc(sizeof(char) * (k + 1));
	if (!j)
		return ;
	if (a == 0 && !tab->pnt)
	{
		j[i] = '0';
		i = 1;
	}
	while (a > 0)
	{
		digit = a % 16;
		j[i] = hex_digits[digit];
		a /= 16;
		i++;
	}
	j[i] = '\0';
	ft_tabs_precisions(tab, j, i);
}

void	ft_tabs_precisions(t_print *tab, char *j, size_t i)
{
	if (tab->wdt && !tab->dash && tab->wdt > tab->prc)
		ft_right_cs_x(tab, j);
	if (i > 0)
	{
		if (!tab->is_zero && tab->hash && j[i - 1] != '0')
		{
			tab->tl += ft_putchar('0');
			tab->tl += ft_putchar('x');
		}
	}	
	ft_precision(tab, j, i);
}
