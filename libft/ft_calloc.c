/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:48:06 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 19:54:43 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > ((size_t)-1 / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
