/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:13:47 by cel-bahr          #+#    #+#             */
/*   Updated: 2024/02/15 22:17:58 by cel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <libc.h>
int ft_printf(const char *format, ...);
void i_print(va_list arg, char c, int *len);
int ft_putchar(char c);
int i_print_str(const char *s);
int i_print_num(long nb);
int i_print_unnum(long nb);
int i_print_hex(unsigned long nbr, int t);
int i_print_adr(void *nbr);

#endif
