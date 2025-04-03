/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:48:27 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 20:01:18 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;

	ss = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*ss == (unsigned char)c)
			return ((void *)ss);
		ss++;
	}
	return (NULL);
}
