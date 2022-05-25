/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_valious.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:36:19 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:34:36 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_strl(char *str, size_t n)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (i < n && *str)
	{
		ft_putchar_fd(*str, 1);
		i++;
		str++;
	}
	return (i);
}

int	ft_put_space(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

int	ft_put_zeo(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (i);
}

int	ft_get_digit(int num)
{
	int	count;

	count = 0;
	if (num == INT_MIN)
		return (11);
	if (num < 0)
	{
		count++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*to_str_upper(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		tmp[i] = ft_toupper(tmp[i]);
		i++;
	}
	return (tmp);
}
