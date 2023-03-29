/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:24:15 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 21:10:08 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static void	ft_update_tab(t_print *tab, int value)
{
	tab->tl += value;
}

static void	ft_right_cs(t_print *tab)
{
	int	pad;

	pad = 0;
	if (tab->wdt > 1 && !tab->zero)
	{
		pad = tab->wdt - 1;
		while (pad--)
		{
			ft_putchar(' ');
			ft_update_tab(tab, 1);
		}
	}
	if (tab->wdt && tab->zero)
	{
		pad = tab->wdt - 1;
		while (pad--)
		{
			ft_putchar('0');
			ft_update_tab(tab, 1);
		}
	}
}

static void	ft_left_cs(t_print *tab)
{
	int	pad;

	pad = 0;
	if (tab->wdt > 1)
		pad = tab->wdt - 1;
	while (pad--)
	{
		ft_putchar(' ');
		ft_update_tab(tab, 1);
	}
}

void	ft_print_percent(t_print *tab)
{
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab);
	tab->tl += ft_putchar('%');
	tab->perc = 1;
	if (tab->wdt && tab->dash)
		ft_left_cs(tab);
	tab->zero = 0;
	tab->dash = 0;
	tab->prc = 0;
	tab->wdt = 0;
}
