/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foncBONUS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:54:38 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/27 19:11:37 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	if (i == -1)
		return (-1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		i += ft_putchar(nb + 48);
	}
	return (i);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbr_unsigned(n / 10);
	}
	i += ft_putchar((n % 10) + '0');
	return (i);
}
