/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:00:01 by yjimpei           #+#    #+#             */
/*   Updated: 2021/06/06 11:49:31 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	big_pre(t_info_list *info, int count, char *tmp, int tmp_len)
{
	if (info->has_minus == 1 && info->precision < info->width)
	{
		count = ft_put_zeo(info->precision - tmp_len);
		count += ft_put_strl(tmp, tmp_len);
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision);
	}
	else
	{
		count = ft_put_space(info->width - info->precision);
		count += ft_put_zeo(info->precision - tmp_len);
		count += ft_put_strl(tmp, tmp_len);
	}
	return (count);
}

static int	else_(t_info_list *info, int count, char *tmp, int tmp_len)
{
	if (info->has_minus == 1)
	{
		count = ft_put_strl(tmp, tmp_len);
		if (info->width > tmp_len)
			count += ft_put_space(info->width - tmp_len);
	}
	else
	{
		if ((info->width > tmp_len && (!info->has_zero || info->precision))
			|| (info->width > tmp_len && info->has_zero && info->has_precision))
			count += ft_put_space(info->width - tmp_len);
		else if (info->width > tmp_len && info->has_zero != 0)
			count += ft_put_zeo(info->width - tmp_len);
		count += ft_put_strl(tmp, tmp_len);
	}
	return (count);
}

int	ft_put_u(t_info_list *info, va_list ap)
{
	char	*tmp;
	int		tmp_len;
	int		count;

	tmp = ft_utoa(va_arg(ap, unsigned int));
	tmp_len = ft_strlen(tmp);
	count = 0;
	if (info->has_precision != 0 && info->precision == 0 && *tmp == '0')
		count += ft_put_space(info->width);
	else if (info->precision > tmp_len)
		count += big_pre(info, count, tmp, tmp_len);
	else
		count += else_(info, count, tmp, tmp_len);
	free(tmp);
	return (count);
}
