/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:48:23 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 20:01:14 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_to_arr(char *arr, unsigned int n, int pos, int size)
{
	int	i;

	i = 0;
	arr = (char *)malloc((size + pos + 1) * sizeof(char));
	if (!arr)
		return (0);
	if (n == 0)
		arr[i++] = 0 + 48;
	while (n)
	{
		arr[i++] = (n % 10) + 48;
		n = n / 10;
	}
	if (pos == 1)
		arr[i++] = '-';
	arr[i] = '\0';
	return (arr);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		i++;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	int		nb;
	char	*arr;

	size = 0;
	nb = n;
	arr = NULL;
	if (nb == 0)
		size = 1;
	while (nb)
	{
		nb = nb / 10;
		size++;
	}
	if (n < 0)
	{
		arr = write_to_arr(arr, (n * -1), 1, size);
	}
	else
		arr = write_to_arr(arr, n, 0, size);
	if (!arr)
		return (0);
	arr = ft_strrev(arr);
	return (arr);
}
