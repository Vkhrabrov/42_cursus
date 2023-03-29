/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:04:28 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 22:14:52 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_print_string_2(t_print *tab, char *a, size_t i);

static void	ft_update_tab(t_print *tab, int value)
{
	tab->tl += value;
}

static void	ft_right_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	if (tab->prc < len && tab->pnt)
		len = tab->prc;
	if (tab->wdt > len)
		pad = tab->wdt - len;
	if (tab->zero == 0)
	{
		while (pad--)
		{
			ft_putchar(' ');
			ft_update_tab(tab, 1);
		}
	}
	else
	{
		while (pad--)
		{
			ft_putchar('0');
			ft_update_tab(tab, 1);
		}
	}
}

static void	ft_left_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	if (tab->prc < len && tab->pnt)
		len = tab->prc;
	if (tab->wdt > len)
		pad = tab->wdt - len;
	while (pad--)
	{
		ft_putchar(' ');
		ft_update_tab(tab, 1);
	}
}

void	ft_print_string(t_print *tab)
{
	char	*a;
	size_t	i;

	i = 0;
	a = va_arg(tab->args, char *);
	if (a == NULL)
		a = "(null)";
	if (tab->pnt != 0)
	{
		if (tab->wdt && !tab->dash)
		{
			ft_right_cs(tab, a);
		}
		while (a[i] && i < (size_t)tab->prc)
			tab->tl += ft_putchar(a[i++]);
		if (tab->wdt && tab->dash)
			ft_left_cs(tab, a);
	}
	ft_print_string_2(tab, a, i);
}

void	ft_print_string_2(t_print *tab, char *a, size_t i)
{
	if (tab->pnt == 0)
	{
		if (tab->wdt && !tab->dash)
		{
			ft_right_cs(tab, a);
		}
		while (*a && i < ft_strlen(a))
		{
			tab->tl += ft_putchar(a[i]);
			i++;
		}
		if (tab->wdt && tab->dash)
			ft_left_cs(tab, a);
	}
	tab->dash = 0;
	tab->zero = 0;
	tab->wdt = 0;
}
