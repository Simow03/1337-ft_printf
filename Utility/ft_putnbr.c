/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:32:09 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 16:16:14 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int d)
{
	long int	nb;
	int			count_digit;
	int			temp;

	temp = d;
	count_digit = 1;
	while ((temp / 10) != 0)
	{
		count_digit++;
		temp /= 10;
	}
	nb = d;
	if (nb < 0)
	{
		write(1, "-", 1);
		count_digit++;
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &("0123456789"[nb % 10]), 1);
	return (count_digit);
}
