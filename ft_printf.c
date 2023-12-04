/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:24:06 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/05 00:48:27 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkconv(const char c, va_list ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (c == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (c == 'p')
		len += ft_putstr("0x") + ft_putptr_hexa(va_arg(ptr, uintptr_t));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(ptr, int));
	else if (c == 'x')
		len += ft_putnbr_hexalower(va_arg(ptr, int));
	else if (c == 'X')
		len += ft_putnbr_hexaupper(va_arg(ptr, int));
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

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
			len += ft_checkflags(str, ptr);
		}
		else
			len += write(1, &(*str), 1);
		str++;
	}
	va_end(ptr);
	return (len);
}
int main()
{
	printf("%d\n",ft_printf("%+     #++++x\n", 123));
	printf("%d\n",printf("%+     #++++x\n", 123));
}