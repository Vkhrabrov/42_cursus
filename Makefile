# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 21:09:07 by vkhrabro          #+#    #+#              #
#    Updated: 2023/03/27 00:59:54 by vkhrabro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a
HEADER = ft_printf.h

SRC_F:= ft_printf ft_print_char ft_print_string	ft_print_pointer ft_print_int ft_printf_unsigned_int ft_calculate_padding_x ft_printf_lower ft_printf_upper ft_print_percent ft_utoa ft_printf_main_add ft_printf_x_lower ft_printf_x_upper ft_eval_format_bonus ft_calculate_padding_right_int ft_calculate_padding_left_int

SRC_B:= ft_eval_format_bonus ft_calculate_padding_right_int ft_calculate_padding_left_int ft_calculate_padding_x

LIBS:= libft/libft.a

FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = $(addsuffix .c, $(SRC_F))
OBJS = $(SRC:.c=.o)
SRC_BNS = $(addsuffix .c, $(SRC_B))
OBJS_BNS = $(SRC_BNS:.c=.o)

CC = gcc

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

all: 	make_libs $(NAME)

bonus: 	make_libs bbonus

make_libs:
		$(MAKE) -C libft/ 

$(NAME): $(OBJS) $(HEADER) $(LIBS)
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS) 

bbonus:  $(OBJS) $(OBJS_BNS) $(HEADER) $(LIBS)
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS) $(OBJS_BNS) 
		@touch bbonus

clean:
	$(RM) $(OBJS) $(OBJS_BNS)
	$(RM) bbonus
	$(MAKE) -C libft/ clean  

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean  

re: fclean all

.PHONY: re clean fclean all
