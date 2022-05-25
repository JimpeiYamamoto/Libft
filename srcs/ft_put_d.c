/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:43:43 by yjimpei           #+#    #+#             */
/*   Updated: 2021/06/06 12:19:17 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	last_else_n_m(int count, t_info_list *info, char *tmp, int tmp_len)
{
	if (*tmp == '-')
	{
		if ((info->width > tmp_len && (!info->has_zero || info->precision))
			|| (info->width > tmp_len && info->has_zero && info->has_precision))
			count += ft_put_space(info->width - tmp_len);
		else if (info->width > tmp_len && info->has_zero != 0)
		{
			ft_putchar_fd('-', 1);
			count++;
			count += ft_put_zeo(info->width - tmp_len);
			count += ft_put_strl(tmp + 1, tmp_len - 1);
			return (count);
		}
	}
	else
	{
		if ((info->width > tmp_len && (!info->has_zero || info->precision))
			|| (info->width > tmp_len && info->has_zero && info->has_precision))
			count += ft_put_space(info->width - tmp_len);
		else if (info->width > tmp_len && info->has_zero != 0)
			count += ft_put_zeo(info->width - tmp_len);
	}
	count += ft_put_strl(tmp, tmp_len);
	return (count);
}

static int	tm_eq_pre_m(int count, t_info_list *info, char *tmp, int tmp_len)
{
	if (info->has_minus == 0)
	{
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision - 1);
		ft_putchar_fd('-', 1);
		count++;
		count += ft_put_zeo(1);
		count += ft_put_strl(tmp + 1, tmp_len - 1);
	}
	else
	{
		ft_putchar_fd('-', 1);
		count++;
		count += ft_put_zeo(1);
		count += ft_put_strl(tmp + 1, tmp_len - 1);
		if (info->width > info->precision)
			count += ft_put_space(info->width - info->precision - 1);
	}
	return (count);
}

static int	big_pre_m_big_wid(int count, t_info_list *info,
								char *tmp, int tmp_len)
{
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

static int	big_pre_else(int count, t_info_list *info, char *tmp, int tmp_len)
{
	if (*tmp == '-')
	{
		count = ft_put_space(info->width - info->precision - 1);
		ft_putchar_fd('-', 1);
		count++;
		count += ft_put_zeo(info->precision - tmp_len + 1);
		count += ft_put_strl(tmp + 1, tmp_len - 1);
	}
	else
	{
		count = ft_put_space(info->width - info->precision);
		count += ft_put_zeo(info->precision - tmp_len);
		count += ft_put_strl(tmp, tmp_len);
	}
	return (count);
}

int	ft_put_d(t_info_list *info, va_list ap)
{
	char	*tmp;
	int		tmp_len;
	int		count;

	tmp = ft_itoa(va_arg(ap, int));
	tmp_len = ft_strlen(tmp);
	count = 0;
	if (info->has_precision != 0 && info->precision == 0 && *tmp == '0')
		count += ft_put_space(info->width);
	else if (info->precision > tmp_len)
	{
		if (info->has_minus == 1 && info->precision < info->width)
			count += big_pre_m_big_wid(count, info, tmp, tmp_len);
		else
			count += big_pre_else(count, info, tmp, tmp_len);
	}
	else if (tmp_len == info->precision && *tmp == '-')
		count += tm_eq_pre_m(count, info, tmp, tmp_len);
	else if (info->has_minus == 1)
		count += d_last_else_m(count, info, tmp, tmp_len);
	else
		count += last_else_n_m(count, info, tmp, tmp_len);
	free(tmp);
	return (count);
}
