/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:39:25 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 22:32:27 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_right_cs_zeroes(t_print *tab, char *a,
				int len, int pad);

static void	ft_right_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;
	int	i;

	i = 0;
	len = ft_strlen(a);
	pad = 0;
	if (tab->wdt > len && !tab->zero)
	{
		pad = tab->wdt - len;
		if (!tab->sign && tab->sp)
			pad = tab->wdt - len;
		if (tab->pnt != 0 && tab->prc > len)
			pad = tab->wdt - tab->prc;
		if (tab->prc < len)
			pad = tab->wdt - len;
		while (pad--)
			tab->tl += ft_putchar(' ');
	}
	ft_right_cs_zeroes(tab, a, len, pad);
}

static int	ft_right_cs_zeroes(t_print *tab, char *a,
				int len, int pad)
{
	int	i;

	i = 0;
	if (tab->wdt > len && tab->zero && tab->pnt)
	{
		tab->zero = 0;
		ft_right_cs(tab, a);
		return (0);
	}
	if (tab->wdt > len && tab->zero && !tab->pnt)
	{
		pad = tab->wdt - len;
		while (pad--)
			tab->tl += ft_putchar('0');
	}
	return (0);
}

static void	ft_left_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	if (tab->wdt > len)
	{
		pad = tab->wdt - len;
		if (tab->pnt != 0 && tab->prc > len)
			pad = tab->wdt - tab->prc;
		if (tab->prc < len)
			pad = tab->wdt - len;
		while (pad--)
			tab->tl += ft_putchar(' ');
	}
}

static void	ft_precision(t_print *tab, char *j, size_t i)
{
	size_t	k;

	if (tab->pnt && (size_t)tab->prc > ft_strlen(j))
	{
		k = tab->prc - ft_strlen(j);
		while (k--)
			tab->tl += ft_putchar('0');
	}
	while (j[i])
	{
		tab->tl += ft_putchar(j[i]);
		i++;
	}
	if (tab->wdt && tab->dash && tab->wdt >= tab->prc)
		ft_left_cs(tab, j);
}

void	ft_printf_unsigned_int(t_print *tab)
{
	size_t			i;
	char			*j;
	unsigned int	a;

	i = 0;
	j = NULL;
	a = va_arg(tab->args, unsigned int);
	j = ft_utoa(a);
	if (tab->pnt && !tab->prc && a == 0)
	{
		free(j);
		j = ft_strdup("");
		if (!j)
			return ;
	}
	if (tab->wdt && !tab->dash && tab->wdt >= tab->prc)
		ft_right_cs(tab, j);
	ft_precision(tab, j, i);
	free(j);
}
