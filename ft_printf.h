/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:53:22 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/05 13:11:50 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int d);
int	ft_putnbr_unsigned(unsigned int u);
int	ft_putptr_hexa(uintptr_t p);
int	ft_putnbr_hexalower(unsigned int x);
int	ft_putnbr_hexaupper(unsigned int x);
int	ft_checkconv(const char c, va_list ptr);
int	ft_checkflags(const char **str, va_list ptr);

#endif