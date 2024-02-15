/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_print_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-bahr <cel-bahr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:51:21 by cel-bahr          #+#    #+#             */
/*   Updated: 2024/02/15 22:17:29 by cel-bahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
int i_print_hex(unsigned long nbr, int t)
{
    int count;
    char H[16]="0123456789ABCDEF";
    char h[16]="0123456789abcdef";

    count = 0;
    if (nbr < 16)
    {
        if (t == 1)
            count +=ft_putchar(H[nbr]);
        else if (t == 0)
            count +=ft_putchar(h[nbr]);
            
    }
    else
    {
        count += i_print_hex(nbr / 16, t);
        count += i_print_hex(nbr % 16, t);
    }
    return (count);
}

int i_print_adr(void *nbr)
{
    int count;
    unsigned long nb;
                                                
    nb = (unsigned long)nbr;
    char h[16] = "0123456789abcdef";
    
    count = 0;
    if (nb < 16)
            count +=ft_putchar(h[nb]);
    else
    {
        count += i_print_adr((void *)(nb / 16));
        count += i_print_adr((void *)(nb % 16));
    }
    return (count);
}