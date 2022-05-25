/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utof2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:27:15 by yjimpei           #+#    #+#             */
/*   Updated: 2022/05/25 10:25:39 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_get(intptr_t n)
{
	int			digit;

	digit = 1;
	while (n > 15)
	{
		n /= 16;
		digit++;
	}
	return (digit);
}

static char	*str_get(char *p_str, intptr_t n, int digit)
{
	char			str[17];
	int				j;
	int				k;
	int				i;
	intptr_t		num;

	ft_strlcpy(str, "0123456789abcdef", 17);
	j = 0;
	i = 0;
	while (j < digit)
	{
		num = n;
		k = j;
		while (k < digit - 1)
		{
			num /= 16;
			k++;
		}
		p_str[i] = str[num % 16];
		j++;
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}

char	*ft_utof2(intptr_t n)
{
	int			digit;
	char		*p_str;

	digit = digit_get(n);
	p_str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!p_str)
		return (NULL);
	return (str_get(p_str, n, digit));
}
