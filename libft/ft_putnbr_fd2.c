/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:17:59 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/23 18:03:51 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd2(int n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		if (n == (-2147483648))
		{
			i += ft_putchar_fd2('-', 1);
			i += ft_putstr_fd2("2147483648", 1);
		}
		else
		{
			i += ft_putchar_fd2('-', 1);
			i += ft_putnbr_fd2(-n, 1);
		}
	}
	else if (n >= 10)
	{
		i += ft_putnbr_fd2(n / 10, 1);
		i += ft_putnbr_fd2(n % 10, 1);
	}
	else
		i += ft_putchar_fd2(n + '0', fd);
	return (i);
}
