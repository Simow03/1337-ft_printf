/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:33:25 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/06 23:20:54 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_ishash(const char **str, va_list ptr)
{
	int	len;
	int	value;

	len = 0;
	value = va_arg(ptr, int);
	(*str)++;
	if (value == 0)
	{
		if (*(*str) == 'x')
			len += ft_putnbr_hexalower(value);
		else if (*(*str) == 'X')
			len += ft_putnbr_hexaupper(value);
		else
			len += ft_checkconv(*(*str), ptr);
	}
	else
	{
		if (*(*str) == 'x')
			len += write(1, "0x", 2) + ft_putnbr_hexalower(value);
		else if (*(*str) == 'X')
			len += write(1, "0X", 2) + ft_putnbr_hexaupper(value);
		else
			len += ft_checkconv(*(*str), ptr);
	}
	return (len);
}

static int	ft_isplus(const char **str, va_list ptr)
{
	int	len;
	int	value;

	len = 0;
	(*str)++;
	if (*(*str) == 'd' || *(*str) == 'i')
	{
		value = va_arg(ptr, int);
		if (value >= 0)
			len += write(1, "+", 1) + ft_putnbr(value);
		else
			len += ft_putnbr(value);
	}
	else
		len += ft_checkconv(*(*str), ptr);
	return (len);
}

static int	ft_isspace(const char **str, va_list ptr)
{
	int	len;
	int	value;

	len = 0;
	(*str)++;
	if (*(*str) == 'd' || *(*str) == 'i')
	{
		value = va_arg(ptr, int);
		if (value >= 0)
			len += write(1, " ", 1) + ft_putnbr(value);
		else
			len += ft_putnbr(value);
	}
	else
		len += ft_checkconv(*(*str), ptr);
	return (len);
}

int	ft_checksecflags(const char **str, va_list ptr)
{
	int	len;

	len = 0;
	if (*(*str) == '#')
		len += ft_ishash(str, ptr);
	else if (*(*str) == '+')
		len += ft_isplus(str, ptr);
	else if (*(*str) == ' ')
		len += ft_isspace(str, ptr);
	return (len);
}
