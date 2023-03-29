/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:56:48 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 22:33:57 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_right_cs_zeroes(t_print *tab, char *a, int len);
void		print_hash_left(t_print *tab, int len, int *pad);
void		ft_apply_padding(t_print *tab, int pad);
int			ft_is_hash_condition(char *a, int len, int pad);
int			calculate_padding_x_left(t_print *tab, char *a, int len, int pad);

void	ft_right_cs_x_upper(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = calculate_padding_x(tab, a, len);
	if (tab->wdt > len && !tab->zero)
	{
		while (pad--)
			tab->tl += ft_putchar(' ');
	}
	ft_right_cs_zeroes(tab, a, len);
}

static int	ft_right_cs_zeroes(t_print *tab, char *a, int len)
{	
	int	pad;

	if (tab->wdt > len && tab->zero && tab->pnt)
	{
		tab->zero = 0;
		ft_right_cs_x(tab, a);
		return (0);
	}
	pad = tab->wdt - len;
	if (tab->wdt > len && tab->zero && !tab->pnt)
	{
		if (tab->hash && len == 4)
			pad = tab->wdt - len - 1;
		if (!tab->sign && tab->sp)
			pad = tab->wdt - len;
		if (tab->pnt && ((tab->prc > len && !tab->hash)
				|| ((tab->hash) && (tab->wdt > tab->prc))))
			pad = tab->wdt - tab->prc;
		if (tab->pnt && tab->prc > len && tab->hash && tab->wdt < tab->prc)
			pad = tab->wdt - tab->prc - 2;
		if (!tab->pnt && tab->hash && ft_is_hash_condition(a, len, pad))
			print_hash_left(tab, len, &pad);
		ft_apply_padding(tab, pad);
	}
	return (0);
}

static void	ft_left_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	if (len == 0 && tab->wdt == tab->prc)
		pad = 0;
	else
		pad = tab->wdt - len;
	pad = calculate_padding_x_left(tab, a, len, pad);
	if (tab->wdt > len && !tab->zero)
	{
		write_padding(tab, pad);
	}
}

void	ft_precision_upper(t_print *tab, char *j, size_t i)
{
	size_t	k;

	if (tab->pnt && (size_t)tab->prc > ft_strlen(j))
	{
		k = tab->prc - ft_strlen(j);
		while (k--)
			tab->tl += ft_putchar('0');
	}
	if (j[0] == '0' && j[1] == '\0')
		tab->tl += ft_putchar(j[0]);
	else
	{
		while (*j && i != 0)
		{
			tab->tl += ft_putchar(j[i - 1]);
			i--;
		}
	}
	if (tab->wdt && tab->dash && tab->wdt >= tab->prc)
		ft_left_cs(tab, j);
	free(j);
}

void	ft_printf_upper(t_print *tab)
{
	unsigned int	a;
	int				digit;

	a = va_arg(tab->args, unsigned int);
	digit = 0;
	ft_printf_x_upper(tab, digit, a);
	tab->zero = 0;
}
