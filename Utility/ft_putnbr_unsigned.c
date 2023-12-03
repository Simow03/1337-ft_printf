/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:37:01 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 15:26:49 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int u)
{
	unsigned int	count_digit;
	unsigned int	temp;
	long int		nb;

	temp = u;
	count_digit = 1;
	while ((temp / 10) != 0)
	{
		count_digit++;
		temp /= 10;
	}
	nb = u;
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	write(1, &("0123456789"[nb % 10]), 1);
	return (count_digit);
}
