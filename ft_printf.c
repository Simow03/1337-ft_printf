/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:24:06 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 19:05:19 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;

	if (!str)
		return (0);
	va_start(ptr, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				len += ft_putchar(va_arg(ptr, int));
			else if (*str == 's')
				len += ft_putstr(va_arg(ptr, char *));
			else if (*str == 'p')
				len += ft_putstr("0x") + ft_putptr_hexa(va_arg(ptr, uintptr_t));
			else if (*str == 'd' || *str == 'i')
				len += ft_putnbr(va_arg(ptr, int));
			else if (*str == 'u')
				len += ft_putnbr_unsigned(va_arg(ptr, int));
			else if (*str == 'x')
				len += ft_putnbr_hexalower(va_arg(ptr, int));
			else if (*str == 'X')
				len += ft_putnbr_hexaupper(va_arg(ptr, int));
			else if (*str == '%')
				len += write(1, "%", 1);
		}
		else
			len += write(1, &(*str), 1);
		str++;
	}
	va_end(ptr);
	return (len);
}
// int main()
// {
// 	// printf("\n%d",ft_printf("\n%s\tuohgogguo%c\t%d\t%i\t%u\t%x\t%X%%\t%p", "hi", 'v', -129, -21904, -21, 235, 142, "fivj"));
// 	// printf("\n%d",printf("\n%s\tuohgogguo%c\t%d\t%i\t%u\t%x\t%X%%\t%p", "hi", 'v', -129, -21904, -21, 235, 142, "fivj"));
// 	printf("%d\n", ft_printf("%X", -10));
// 	printf("%d\n", printf("%X", -10));
// }