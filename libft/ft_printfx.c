/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:50:35 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/23 18:04:30 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenhexa(unsigned long n)
{
	int	c;

	c = 0;
	while (n != 0)
	{
		n = n / 16;
		c++;
	}
	return (c);
}

int	ft_printfx(unsigned long n, char *hexa)
{
	char	*hex;
	int		size;
	int		result;

	size = ft_lenhexa(n);
	if (n == 0)
		return (ft_putchar_fd2('0', 1));
	hex = malloc(size + 1);
	if (hex == NULL)
		return (-1);
	hex[size] = '\0';
	while (size > 0)
	{
		size--;
		hex[size] = hexa[n % 16];
		n = n / 16;
	}
	result = ft_putstr_fd2(hex, 1);
	free(hex);
	return (result);
}
