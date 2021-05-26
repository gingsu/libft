/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:58:00 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 14:39:52 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long long n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	long long	num;
	int			len;
	char		*dest;

	num = (long long)n;
	if (n < 0)
	{
		num *= -1;
		len = ft_num_len(num) + 1;
	}
	else
		len = ft_num_len(num);
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len--] = '\0';
	while (num / 10 != 0)
	{
		dest[len--] = num % 10 + '0';
		num /= 10;
	}
	dest[len--] = num + '0';
	if (n < 0)
		dest[len] = '-';
	return (dest);
}
