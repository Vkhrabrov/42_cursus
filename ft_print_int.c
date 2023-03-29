/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:27:37 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 21:39:00 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_right_cs_zeroes(t_print *tab, char *a,
				int len);

static void	ft_right_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	calculate_padding(tab, a, len, &pad);
	write_padding(tab, pad);
	ft_right_cs_zeroes(tab, a, len);
}

static int	ft_right_cs_zeroes(t_print *tab, char *a, int len)
{
	if (tab->wdt != tab->prc && tab->wdt > len && tab->zero && tab->pnt)
	{
		tab->zero = 0;
		ft_right_cs(tab, a);
		return (0);
	}
	if (a[0] == '-' && tab->zero)
		tab->tl += ft_putchar('-');
	if (!tab->sign && tab->sp && a[0] != '-' && tab->wdt != tab->prc)
	{
		tab->is_zero = 1;
		tab->tl += ft_putchar(' ');
	}
	if (tab->sign && !tab->sp && a[0] != '-' && tab->wdt != tab->prc)
	{
		tab->is_zero = 1;
		tab->tl += ft_putchar('+');
	}
	if (ft_zero_pad(tab, a, len))
		return (0);
	return (0);
}

static void	ft_left_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	calculate_left_padding(tab, a, len, &pad);
	write_padding(tab, pad);
}

static void	ft_precision(t_print *tab, char *j, size_t i)
{
	size_t	k;

	if (!tab->is_zero && !tab->sign && tab->sp && tab->zero && j[i] != '-')
		tab->tl += ft_putchar(' ');
	if (tab->pnt && (size_t)tab->prc > ft_strlen(j) - 1)
	{
		if (j[i] == '-')
			k = tab->prc - ft_strlen(j) + 1;
		else
			k = tab->prc - ft_strlen(j);
		while (k--)
			tab->tl += ft_putchar('0');
	}
	if (j[i] == '-')
		i++;
	while (j[i])
	{
		tab->tl += ft_putchar(j[i]);
		i++;
	}
	if (tab->wdt && tab->dash && tab->wdt >= tab->prc
		&& (!(tab->wdt == tab->prc && (size_t)tab->prc > ft_strlen(j))))
		ft_left_cs(tab, j);
}

void	ft_print_int(t_print *tab)
{
	size_t	i;
	char	*j;
	int		a;

	i = 0;
	j = NULL;
	a = va_arg(tab->args, int);
	j = ft_itoa(a);
	if (tab->pnt && !tab->prc && a == 0)
		empty_string(&j);
	if (tab->wdt && !tab->dash && tab->wdt >= tab->prc)
		ft_right_cs(tab, j);
	if (j[i] == '-' && tab->zero && ((tab->wdt < tab->prc)
			|| (!tab->wdt && !tab->prc)))
		tab->tl += ft_putchar('-');
	if (j[i] == '-' && !tab->zero)
		tab->tl += ft_putchar('-');
	if (!tab->is_zero && tab->sign && !(j[i] == '-'))
		tab->tl += ft_putchar('+');
	if (!tab->is_zero && !tab->sign && tab->sp && !tab->zero && j[i] != '-')
		tab->tl += ft_putchar(' ');
	ft_precision(tab, j, i);
	tab->zero = 0;
	free(j);
}
