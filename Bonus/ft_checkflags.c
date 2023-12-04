/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:33:25 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/05 00:47:46 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_checkHash(const char *str, va_list ptr)
{
	int	len;

	len = 0;
	while (*str == '#' || *str == ' ' || *str == '+')
		str++;
	if (*str == 'x')
		len += write(1, "0x", 2) + ft_putnbr_hexalower(va_arg(ptr, int));
	else if (*str == 'X')
		len += write(1, "0X", 2) + ft_putnbr_hexaupper(va_arg(ptr, int));
	else
		len += ft_checkconv(*str, ptr);
	return (len);
}

static int	ft_checkPlus(const char *str, va_list ptr)
{
	int	len;
	int	value;

	len = 0;
	while (*str == '+' || *str == ' ' || *str == '#')
		str++;
	if (*str == 'd' || *str == 'i')
	{
		value = va_arg(ptr, int);
		if (value >= 0)
			len += write(1, "+", 1) + ft_putnbr(value);
		else
			len += ft_putnbr(value);
	}
	else
		len += ft_checkconv(*str, ptr);
	return (len);
}

static int	ft_checkSpace(const char *str, va_list ptr)
{
	int	len;
	int	value;

	len = 0;
	while (*str == ' ' || *str == '+' || *str == '#')
		str++;
	if (*str == 'd' || *str == 'i')
	{
		value = va_arg(ptr, int);
		if (value >= 0)
			len += write(1, " ", 1) + ft_putnbr(value);
		else
			len += ft_putnbr(value);
	}
	else
		len += ft_checkconv(*str, ptr);
	return (len);
}

int	ft_checkflags(const char *str, va_list ptr)
{
	int	len;

	len = 0;
	if (*str == '#')
		len += ft_checkHash(str, ptr);
	else if (*str == '+')
		len += ft_checkPlus(str, ptr);
	else if (*str == ' ')
		len += ft_checkSpace(str, ptr);
	else
		len += ft_checkconv(*str, ptr);
	return (len);
}
