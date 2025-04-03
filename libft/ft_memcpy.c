/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:48:32 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 20:01:24 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!dest && !src)
		return (0);
	if (src == dest)
		return ((void *)src);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (n-- > 0)
		*destination++ = *source++;
	return (dest);
}
