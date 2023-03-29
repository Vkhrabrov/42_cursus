/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_padding_left_int.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 23:59:35 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 21:34:35 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <stdlib.h>
#include "libft/libft.h"

void	calculate_left_padding(t_print *tab, char *a, int len, int *pad)
{
	if (tab->wdt > len)
	{
		*pad = tab->wdt - len;
		if ((tab->sign || tab->sp) && tab->wdt == tab->prc)
			*pad = 0;
		if ((tab->sp || tab->sign) && tab->wdt < tab->prc && tab->prc < len)
			*pad = tab->wdt - len - 1;
		if ((tab->sp || tab->sign) && tab->wdt > tab->prc && a[0] == '-'
			&& tab->prc < len)
			*pad = tab->wdt - len;
		if ((tab->sp || tab->sign) && tab->wdt > tab->prc && a[0] != '-'
			&& tab->prc < len)
			*pad = tab->wdt - len - 1;
		if ((tab->sign || tab->sp) && tab->wdt != tab->prc && tab->pnt != 0
			&& tab->prc >= len)
			*pad = tab->wdt - tab->prc - 1;
		if (!tab->sign && !tab->sp && tab->pnt != 0 && a[0] != '-'
			&& tab->prc > len)
			*pad = tab->wdt - tab->prc;
		if ((!tab->sp && !tab->sign) && tab->pnt != 0 && a[0] == '-')
			*pad = tab->wdt - tab->prc - 1;
		if (!tab->sp && !tab->sign && tab->prc < len)
			*pad = tab->wdt - len;
	}
}

void	empty_string(char **j)
{
	free(*j);
	*j = ft_strdup("");
	if (!j)
		return ;
}

void	print_hash_left(t_print *tab, int len, int *pad)
{
	tab->is_zero = 1;
	tab->tl += ft_putchar('0');
	tab->tl += ft_putchar('X');
	*pad = tab->wdt - len - 2;
}
