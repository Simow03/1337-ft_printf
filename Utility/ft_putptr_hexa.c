/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:28:23 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 16:16:20 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr_hexa(uintptr_t p)
{
	int	count;

	count = 0;
	if (p > 15)
		count += ft_putptr_hexa(p / 16);
	count += write(1, &("0123456789abcdef"[p % 16]), 1);
	return (count);
}
