/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfBONUS.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:48:18 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/27 19:11:13 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ahmed(const char *s, size_t i, va_list arg)
{
	if (s[i] == 'c')
		return (ft_putchar((char)va_arg(arg, int)));
	else if (s[i] == 'd' || s[i] == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (s[i] == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (s[i] == 'p')
		return (ft_com((unsigned long)va_arg(arg, void *)));
	else if (s[i] == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else if (s[i] == 'x' || s[i] == 'X')
	{
		if (s[i] == 'x')
			return (ft_heddec(va_arg(arg, int)));
		else
			return (ft_heddecmaj(va_arg(arg, int)));
	}
	else if (s[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	test(char s)
{
	int		i;
	char	*p;

	p = "dcspiuxX%";
	i = 0;
	while (p[i])
	{
		if (p[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!s)
		return (-1);
	va_start(arg, s);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == '%' && test(s[i + 1]) == 1)
		{
			i++;
			l += ahmed(s, i, arg);
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			return (-1);
		else
			l += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (l);
}
