/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:55:43 by yjimpei           #+#    #+#             */
/*   Updated: 2022/05/25 10:26:10 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	big_pre(t_info_list *info, char *tmp, int tmp_len)
{
	int	count;

	count = 0;
	if (info->has_minus != 0 && info->precision < info->width)
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_put_zeo(info->precision - tmp_len + 2);
		count += ft_put_strl(tmp, tmp_len);
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision);
	}
	else
	{
		count += ft_put_space(info->width - info->precision);
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_put_zeo(info->precision - tmp_len + 2);
		count += ft_put_strl(tmp, tmp_len);
	}
	return (count);
}

static int	pre_num_zero(t_info_list *info, int tmp_len)
{
	int	count;

	count = 0;
	if (info->has_minus != 0 && info->precision < info->width)
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_put_zeo(info->precision - tmp_len);
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision - 2);
	}
	else
	{
		count += ft_put_space(info->width - 2);
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_put_zeo(info->precision - tmp_len);
	}
	return (count);
}

static int	else_m(t_info_list *info, int tmp_len, char *tmp)
{
	int	count;

	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_put_strl(tmp, tmp_len);
	if (info->width > tmp_len)
		count += ft_put_space(info->width - tmp_len);
	return (count);
}

static int	else_(t_info_list *info, int tmp_len, char *tmp)
{
	int	count;

	count = 0;
	if (info->width > tmp_len && (info->has_zero == 0 || info->precision != 0))
	{
		count += ft_put_space(info->width - tmp_len);
		ft_putstr_fd("0x", 1);
		count += 2;
	}
	else if (info->width > tmp_len && info->has_zero != 0)
	{
		ft_putstr_fd("0x", 1);
		count += 2;
		count += ft_put_zeo(info->width - tmp_len);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		count += 2;
	}
	count += ft_put_strl(tmp, tmp_len);
	return (count);
}

int	ft_put_p(t_info_list *info, va_list ap)
{
	char		*tmp;
	int			tmp_len;
	int			count;
	intptr_t	num;

	num = va_arg(ap, intptr_t);
	tmp = ft_utof2(num);
	count = 0;
	tmp_len = ft_strlen(tmp) + 2;
	if (info->has_precision != 0 && info->precision > tmp_len)
		count += big_pre(info, tmp, tmp_len);
	else if (info->has_precision != 0 && info->precision == 0 && num == 0)
		count += pre_num_zero(info, tmp_len);
	else if (info->has_minus == 1)
		count += else_m(info, tmp_len, tmp);
	else
		count += else_(info, tmp_len, tmp);
	free(tmp);
	return (count);
}
