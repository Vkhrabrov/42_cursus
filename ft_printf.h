/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:44:00 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/03/27 03:23:38 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stddef.h>
# include<stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
	int		hash;
	int		pos;
	int		minus;
}			t_print;
void		write_padding_x(t_print *tab, int pad);
int			calculate_padding_x(t_print *tab, char *a, int len);
void		empty_string(char **j);
void		calculate_left_padding(t_print *tab, char *a, int len, int *pad);
int			ft_zero_pad(t_print *tab, char *a, int len);
void		write_padding(t_print *tab, int pad);
void		calculate_padding(t_print *tab, char *a, int len, int *pad);
int			ft_printf(const char *format, ...);
void		ft_print_char(t_print *tab);
void		ft_print_string(t_print *tab);
void		ft_print_pointer(t_print *tab);
void		ft_print_int(t_print *tab);
void		ft_print_unsigned_int(t_print *tab);
char		*ft_utoa(unsigned int n);
void		ft_print_lower(t_print *tab);
void		ft_print_upper(t_print *tab);
void		ft_print_percent(t_print *tab);
void		ft_printf_main_add(t_print *tab,
				const char *format, int i, int total);
int			ft_is_valid_specifier(char c);
void		ft_eval_format_bonus(t_print *tab, const char *format, int pos);
void		ft_eval_conversion(t_print *tab, const char *format, int pos);
void		ft_printf_unsigned_int(t_print *tab);
void		ft_printf_lower(t_print *tab);
void		ft_printf_x_lower(t_print *tab, int digit,
				unsigned int a);
void		ft_printf_x_upper(t_print *tab, int digit,
				unsigned int a);
void		ft_right_cs_x(t_print *tab, char *a);
void		ft_printf_upper(t_print *tab);
#endif

/*	va_list args; arg to print out
    int     wdt;  width
    int     prc;  precision
    int     zero; xero padding
    int     pnt;   . 
    int     dash;  - 
    int     tl;    total_length 
    int     sign;  positive or negative number
    int     is_zero; is number zero
    int     perc;  %  
    int     sp;  space flag '  '
*/	
