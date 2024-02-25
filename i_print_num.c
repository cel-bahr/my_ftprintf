/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:52:18 by cel-bahr          #+#    #+#             */
/*   Updated: 2024/02/25 01:26:03 by cel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	i_print_num(long nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		count = i_print_num(-nb) + 1;
	}
	else if (nb > 9)
	{
		count = i_print_num(nb / 10);
		count += i_print_num(nb % 10);
	}
	else
		count += ft_putchar(nb + 48);
	return (count);
}

int	i_print_unnum(long nb)
{
	return (i_print_num((unsigned)nb));
}
