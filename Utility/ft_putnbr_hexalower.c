/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexalower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:37:53 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 18:58:11 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_hexalower(unsigned int x)
{
	long int	nb;
	int			count_digit;

	count_digit = 0;
	nb = x;
	if (nb > 15)
		count_digit += ft_putnbr_hexalower(nb / 16);
	count_digit += write(1, &("0123456789abcdef"[nb % 16]), 1);
	return (count_digit);
}
