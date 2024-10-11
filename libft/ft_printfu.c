/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:33:02 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/23 18:04:35 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfu(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar_fd2(nb + 48, 1);
	else
	{
		i += ft_putnbr_fd2(nb / 10, 1);
		i += ft_putchar_fd2(nb % 10 + 48, 1);
	}
	return (i);
}
