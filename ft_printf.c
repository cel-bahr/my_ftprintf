/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:52:17 by cel-bahr          #+#    #+#             */
/*   Updated: 2024/02/27 23:56:15 by cel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	i_print(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		len += i_print_str(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		len += i_print_num(va_arg(arg, int));
	else if (c == 'u')
		len += i_print_unnum(va_arg(arg, unsigned int));
	else if (c == 'p')
	{
		i_print_str("0x");
		len += 2;
		len += i_print_adr(va_arg(arg, void *));
	}
	else if (c == 'x')
		len += i_print_hex(va_arg(arg, unsigned int), 0);
	else if (c == 'X')
		len += i_print_hex(va_arg(arg, unsigned int), 1);
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		lenght;
	va_list	arg;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start(arg, format);
	i = 0;
	lenght = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			lenght += i_print(arg, format[++i]);
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			lenght++;
		}
		i++;
	}
	va_end(arg);
	return (lenght);
}
