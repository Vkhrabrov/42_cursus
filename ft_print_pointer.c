/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:47:02 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/28 22:12:10 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	ft_print_pointer_second_part(t_print *tab, char *buffer, int digit);

static void	ft_update_buffer(t_print *tab, char *buffer,
				int digit, unsigned long address)
{
	int		i;
	char	*hex_digits;

	i = 2;
	hex_digits = "0123456789abcdef";
	if (address == 0)
	{
		buffer[2] = '0';
		buffer[3] = '\0';
	}
	else
	{
		while (address > 0)
		{
			digit = address % 16;
			buffer[i++] = hex_digits[digit];
			address /= 16;
		}
		buffer[i] = '\0';
	}
	ft_print_pointer_second_part(tab, buffer, digit);
}

static void	ft_right_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	if (tab->wdt > len)
		pad = tab->wdt - len;
	while (pad--)
		tab->tl += ft_putchar(' ');
}

static void	ft_left_cs(t_print *tab, char *a)
{
	int	len;
	int	pad;

	len = ft_strlen(a);
	pad = 0;
	if (tab->wdt > len)
		pad = tab->wdt - len;
	while (pad--)
		tab->tl += ft_putchar(' ');
}

void	ft_print_pointer(t_print *tab)
{
	unsigned long	address;
	char			*hex_digits;
	char			buffer[20];
	int				i;
	int				digit;

	i = 2;
	digit = 0;
	hex_digits = "0123456789abcdef";
	buffer[0] = '0';
	buffer[1] = 'x';
	address = (unsigned long)va_arg(tab->args, void *);
	ft_update_buffer(tab, buffer, digit, address);
}

void	ft_print_pointer_second_part(t_print *tab, char *buffer, int digit)
{
	int	j;

	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, buffer);
	tab->tl += ft_putchar(buffer[0]);
	tab->tl += ft_putchar(buffer[1]);
	if (digit == 0)
	{
		tab->tl += ft_putchar('0');
	}
	else if (digit != 0)
	{
		j = ft_strlen(buffer) - 1;
		while (*buffer && j >= 2)
		{	
			tab->tl += ft_putchar(buffer[j]);
			j--;
		}
	}
	if (tab->wdt && tab->dash && tab->wdt >= tab->prc)
		ft_left_cs(tab, buffer);
	tab->wdt = 0;
	tab->dash = 0;
	tab->zero = 0;
	tab->prc = 0;
}
