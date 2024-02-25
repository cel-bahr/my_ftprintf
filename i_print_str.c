/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:18:52 by cel-bahr          #+#    #+#             */
/*   Updated: 2024/02/25 01:26:16 by cel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	i_print_str(const char *s)
{
	int	i;

	if (s == NULL)
		return (i_print_str("(null)"));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
