/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_padding_right_int.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:33:36 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 22:37:37 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

void	calculate_padd_first_(t_print *tab, char *a, int len, int *pad)
{
	*pad = tab->wdt - len;
	if (tab->sign || tab->sp || tab->dash || tab->wdt == tab->prc)
		*pad = 0;
	if ((tab->sp || tab->sign) && tab->wdt < tab->prc && tab->prc < len)
		*pad = tab->wdt - len - 2;
	if ((tab->sp || tab->sign) && tab->wdt > tab->prc
		&& a[0] == '-' && tab->prc < len)
		*pad = tab->wdt - len;
	if ((tab->sp || tab->sign) && tab->wdt > tab->prc
		&& a[0] != '-' && tab->prc < len)
	{
		if (tab->wdt <= len)
			*pad = tab->wdt - len;
		else
			*pad = tab->wdt - len - 1;
	}
}

void	calculate_padding(t_print *tab, char *a, int len, int *pad)
{
	if (tab->wdt > len && !tab->zero)
	{
		calculate_padd_first_(tab, a, len, pad);
		if ((tab->sign || tab->sp) && tab->wdt != tab->prc && tab->prc >= len)
			*pad = tab->wdt - tab->prc - 1;
		if (!tab->sign && !tab->sp && tab->pnt != 0
			&& a[0] != '-' && tab->prc > len && tab->wdt != tab->prc)
			*pad = tab->wdt - tab->prc;
		if ((!tab->sp && !tab->sign) && tab->wdt != tab->prc
			&& tab->pnt != 0 && a[0] == '-')
			*pad = tab->wdt - tab->prc - 1;
		if (!tab->sp && !tab->sign && tab->prc < len)
			*pad = tab->wdt - len;
	}
}

void	write_padding(t_print *tab, int pad)
{
	while (pad--)
		tab->tl += ft_putchar(' ');
}

int	ft_zero_pad(t_print *tab, char *a, int len)
{
	int	pad;

	if (tab->wdt > len && tab->zero && !tab->pnt)
	{
		if (tab->sign && a[0] != '-')
			pad = tab->wdt - len - 1;
		else if (!tab->sign && a[0] != '-' && tab->sp)
			pad = tab->wdt - len - 1;
		else
			pad = tab->wdt - len;
		while (pad--)
			tab->tl += ft_putchar('0');
		return (1);
	}
	return (0);
}
