/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:32:11 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/24 09:41:43 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(char specific, va_list ap)
{
	int	count;

	count = 0;
	if (specific == 'c')
		count += ft_putchar_fd2(va_arg(ap, int), 1);
	else if (specific == 's')
		count += ft_putstr_fd2(va_arg(ap, char *), 1);
	else if (specific == 'd' || specific == 'i')
		count += ft_putnbr_fd2(va_arg(ap, int), 1);
	else if (specific == 'x')
		count += ft_printfx(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (specific == 'X')
		count += ft_printfx(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (specific == 'p')
		count += ft_printadres(va_arg(ap, unsigned long));
	else if (specific == 'u')
		count += ft_printfu(va_arg(ap, unsigned int));
	else if (specific == '%')
		count += ft_putchar_fd2('%', 1);
	else
		count += ft_putchar_fd2(specific, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_checker(s[i], ap);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
