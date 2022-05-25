/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 21:17:10 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:28:10 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mi_big_wid(char *tmp, int tmp_len, t_info_list *info)
{
	int	count;

	count = 0;
	if (*tmp == '-')
	{
		ft_putchar_fd('-', 1);
		count++;
		count += ft_put_zeo(info->precision - tmp_len + 1);
		count += ft_put_strl(tmp + 1, tmp_len - 1);
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision - 1);
	}
	else
	{
		count = ft_put_zeo(info->precision - tmp_len);
		count += ft_put_strl(tmp, tmp_len);
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision);
	}
	return (count);
}
