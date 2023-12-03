/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexalower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:37:53 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 16:15:54 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_hexalower(int x)
{
	long int	nb;
	int			count_digit;
	int			temp;

	temp = x;
	count_digit = 1;
	while ((temp / 16) != 0)
	{
		count_digit++;
		temp /= 16;
	}
	nb = x;
	if (nb < 0)
	{
		write(1, "-", 1);
		count_digit++;
		nb *= -1;
	}
	if (nb > 15)
		ft_putnbr_hexalower(nb / 16);
	write(1, &("0123456789abcdef"[nb % 16]), 1);
	return (count_digit);
}
