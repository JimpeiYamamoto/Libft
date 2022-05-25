/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 00:15:41 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/19 23:08:38 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_flow(long num, int minus, long next)
{
	if ((num * minus) > (LONG_MAX / 10))
		return ((int)LONG_MAX);
	if ((num * minus) == (LONG_MAX / 10) && next > (LONG_MAX % 10))
		return ((int)LONG_MAX);
	if ((num * minus) < (LONG_MIN / 10))
		return ((int)LONG_MIN);
	if ((num * minus) == (LONG_MIN / 10) && (next * -1) < (LONG_MIN % 10))
		return ((int)LONG_MIN);
	return (42);
}

static long	make_num(const char *nptr, long minus)
{
	long	num;

	if (*nptr >= '0' && *nptr <= '9')
	{
		num = *nptr - '0';
		nptr++;
		while (*nptr && *nptr >= '0' && *nptr <= '9')
		{
			num *= 10;
			if (check_flow(num, minus, *nptr - '0') != 42)
				return (check_flow(num, minus, *nptr - '0'));
			num += *nptr - '0';
			nptr++;
		}
		return ((int)(num * minus));
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	minus;

	minus = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	return (make_num(nptr, minus));
}
