/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:12:10 by ohassani          #+#    #+#             */
/*   Updated: 2024/01/23 18:04:57 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printadres(unsigned long n)
{
	int	i;

	i = 0;
	if (!n)
		return (ft_putstr_fd2("0x0", 1));
	i += ft_putstr_fd2("0x", 1);
	i += ft_printfx(n, "0123456789abcdef");
	return (i);
}
