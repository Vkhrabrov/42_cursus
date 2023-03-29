/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:04:51 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 21:06:52 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_update_tab(t_print *tab, int value)
{
	tab->tl += value;
}

void	ft_right_cs(t_print *tab)
{
	int	pad;

	pad = tab->wdt - 1;
	if (!tab->zero)
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

void	ft_left_cs(t_print *tab)
{
	int	pad;

	pad = tab->wdt - 1;
	while (pad--)
	{
		ft_putchar(' ');
		ft_update_tab(tab, 1);
	}
}

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	ft_update_tab(tab, 1);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab);
	ft_putchar(a);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab);
	tab->dash = 0;
	tab->zero = 0;
}
