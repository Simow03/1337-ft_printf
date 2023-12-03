/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexaupper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:02:23 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 19:04:47 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_hexaupper(unsigned int x)
{
	long int	nb;
	int			count_digit;

	count_digit = 0;
	nb = x;
	if (nb > 15)
		count_digit += ft_putnbr_hexaupper(nb / 16);
	count_digit += write(1, &("0123456789ABCDEF"[nb % 16]), 1);
	return (count_digit);
}
