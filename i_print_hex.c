/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:51:21 by cel-bahr          #+#    #+#             */
/*   Updated: 2024/02/25 01:34:46 by cel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	i_print_hex(unsigned long nbr, int t)
{
	int		count;
	char	*k;
	char	*h;

	h = "0123456789abcdef";
	k = "0123456789ABCDEF";
	count = 0;
	if (nbr < 16)
	{
		if (t == 1)
			count += ft_putchar(k[nbr]);
		else if (t == 0)
			count += ft_putchar(h[nbr]);
	}
	else
	{
		count += i_print_hex(nbr / 16, t);
		count += i_print_hex(nbr % 16, t);
	}
	return (count);
}

int	i_print_adr(void *nbr)
{
	int				count;
	unsigned long	nb;
	char			*h;

	h = "0123456789abcdef";
	nb = (unsigned long)nbr;
	count = 0;
	if (nb < 16)
		count += ft_putchar(h[nb]);
	else
	{
		count += i_print_adr((void *)(nb / 16));
		count += i_print_adr((void *)(nb % 16));
	}
	return (count);
}
