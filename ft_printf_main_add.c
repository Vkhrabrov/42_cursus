/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:16:49 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 22:30:38 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_printf_main_add(t_print *tab, const char *format, int i, int total)
{
	tab->tl = total;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			ft_eval_format_bonus(tab, format, i + 1);
			ft_eval_conversion(tab, format, tab->pos);
			tab->pnt = 0;
			tab->prc = 0;
			tab->wdt = 0;
			tab->dash = 0;
			tab->is_zero = 0;
			i++;
			while (format[i] && !ft_is_valid_specifier(format[i]))
				i++;
		}
		else
			tab->tl += ft_putchar(format[i]);
	}
}
