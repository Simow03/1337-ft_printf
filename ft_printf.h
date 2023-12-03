/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:53:22 by mstaali           #+#    #+#             */
/*   Updated: 2023/12/03 15:16:37 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int d);
int	ft_putnbr_unsigned(unsigned int u);
int	ft_putptr_hexa(uintptr_t p);
int	ft_putnbr_hexalower(int x);
int	ft_putnbr_hexaupper(int x);

#endif