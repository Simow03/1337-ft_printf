/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:57:14 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/02 23:52:04 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int ft_putstr(char *s)
{
	int count;

	count = -1;
	while (s && s[++count])
		write(1, &s[count], 1);
	return (count);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_puthexa(void *p)
{
	int count;
	return (count);
}

int	ft_putnbr(int d)
{
	long int	nb;
	int	count_digit;
	int	temp;

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
		write(1 , "-", 1);
		count_digit++;
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1 , &("0123456789"[nb % 10]), 1);
	return (count_digit);
}
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
	write(1 , &("0123456789"[nb % 10]), 1);
	return (count_digit);
}

int	ft_putnbr_hexalower(int x)
{
	long int	nb;
	int	count_digit;
	int	temp;

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
		write(1 , "-", 1);
		count_digit++;
		nb *= -1;
	}
	if (nb > 15)
		ft_putnbr_hexalower(nb / 16);
	write(1 , &("0123456789abcdef"[nb % 16]), 1);
	return (count_digit);
}

int	ft_putnbr_hexaupper(int x)
{
	long int	nb;
	int	count_digit;
	int	temp;

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
		write(1 , "-", 1);
		count_digit++;
		nb *= -1;
	}
	if (nb > 15)
		ft_putnbr_hexaupper(nb / 16);
	write(1 , &("0123456789ABCDEF"[nb % 16]), 1);
	return (count_digit);
}

int ft_printf(const char *str, ...)
{
	va_list ptr;
	va_start(ptr, str);
	int len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
			{
				len += ft_putchar(va_arg(ptr, int));
				str++;
			}
			else if (*(str + 1) == 's')
			{
				len += ft_putstr(va_arg(ptr, char *));
				str++;
			}
			else if (*(str + 1) == 'p')
			{
				len += ft_puthexa(va_arg(ptr, void *));
				str++;
			}
			else if (*(str + 1) == 'd' || *(str + 1) == 'i')
			{
				len += ft_putnbr(va_arg(ptr, int));
				str++;
			}
			else if (*(str + 1) == 'u')
			{
				len += ft_putnbr_unsigned(va_arg(ptr, int));
				str++;
			}
			else if (*(str + 1) == 'x')
			{
				len += ft_putnbr_hexalower(va_arg(ptr, int));
				str++;
			}
			else if (*(str + 1) == 'X')
			{
				len += ft_putnbr_hexaupper(va_arg(ptr, int));
				str++;
			}
			else if (*(str + 1) == '%')
			{
				len++;
				putchar('%');
				str++;
			}
		}
		else
			len += write(1, &(*str), 1);
		str++;
	}
	return (len);
}

int main()
{
	printf("\n%d",ft_printf("\n%s\tuohgogguo%c\t%d\t%i\t%u\t%x\t%X%%%%", "hi", 'v', -129, -21904, -21, 235, 142));
	printf("\n%d",printf("\n%s\tuohgogguo%c\t%d\t%i\t%u\t%x\t%X%%%%", "hi", 'v', -129, -21904, -21, 235, 142));
}