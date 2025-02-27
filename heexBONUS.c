/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heexBONUS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:52:33 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/27 19:11:52 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr(unsigned long n)
{
	char	*t;
	int		i;

	t = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i += ptr(n / 16);
	i += ft_putchar(t[n % 16]);
	return (i);
}

int	ft_com(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	i += ft_putchar('0');
	i += ft_putchar('x');
	i += ptr(n);
	return (i);
}

int	ft_heddec(unsigned int n)
{
	char	*t;
	int		i;

	t = "0123456789abcdef";
	i = 0;
	if (n >= 16)
		i += ft_heddec(n / 16);
	i += ft_putchar(t[n % 16]);
	return (i);
}

int	ft_heddecmaj(unsigned int n)
{
	char	*t;
	int		i;

	t = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
		i += ft_heddecmaj(n / 16);
	i += ft_putchar(t[n % 16]);
	return (i);
}
