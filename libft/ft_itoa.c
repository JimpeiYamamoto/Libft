/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:53:19 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/19 23:16:11 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit_(int n)
{
	int			digit;
	long long	num;

	num = (long long)n;
	if (num < 0)
		num *= -1;
	digit = 1;
	while (num > 9)
	{
		num /= 10;
		digit++;
	}
	return (digit);
}

static char	*make_str(long long n, int digit, char *p_str, int i)
{
	int			j;
	int			k;
	long long	num;
	long long	digit_num;

	j = 0;
	while (j < digit)
	{
		num = n;
		k = j;
		while (k < digit - 1)
		{
			num /= 10;
			k++;
		}
		digit_num = num % 10;
		p_str[i] = (digit_num) + '0';
		j++;
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}

char	*ft_itoa(int n)
{
	int			digit;
	char		*p_str;
	int			i;
	long long	num;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	digit = get_digit_(n);
	if (n < 0)
		p_str = (char *)malloc(sizeof(char) * (digit + 2));
	else
		p_str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!p_str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		p_str[i] = '-';
		num = n * -1;
		i++;
	}
	else
		num = n;
	p_str = make_str(num, digit, p_str, i);
	return (p_str);
}
