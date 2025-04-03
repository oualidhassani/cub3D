/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:49:30 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 20:02:37 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_if_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!set || !s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	while (check_if_set(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (check_if_set(s1[j], set))
		j--;
	return (ft_substr(s1, i, (j - i) + 1));
}
