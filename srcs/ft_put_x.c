/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:47:04 by yjimpei           #+#    #+#             */
/*   Updated: 2021/06/06 12:30:30 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	big_pre(char *tmp, int tmp_len, t_info_list *info)
{
	int	count;

	count = 0;
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

static int	last_else(char *tmp, int tmp_len, t_info_list *info)
{
	int	count;

	count = 0;
	if ((info->width > tmp_len && (!info->has_zero || info->precision))
		|| (info->width > tmp_len && info->has_zero && info->has_precision))
	{
		count = ft_put_space(info->width - tmp_len);
		count += ft_put_strl(tmp, tmp_len);
		return (count);
	}
	else if (*tmp == '-' && info->width > tmp_len && info->has_zero != 0)
	{
		ft_putchar_fd('-', 1);
		count = ft_put_zeo(info->width - tmp_len);
		count += ft_put_strl(tmp + 1, tmp_len - 1) + 1;
		return (count);
	}
	else if (*tmp != '-' && info->width > tmp_len && info->has_zero != 0)
		count = ft_put_zeo(info->width - tmp_len);
	count += ft_put_strl(tmp, tmp_len);
	return (count);
}

static int	else_m(char *tmp, int tmp_len, t_info_list *info)
{
	int	count;

	count = ft_put_strl(tmp, tmp_len);
	if (info->width > tmp_len)
		count += ft_put_space(info->width - tmp_len);
	return (count);
}

static int	minus_ep(char *tmp, int tmp_len, t_info_list *info)
{
	int	count;

	count = 0;
	ft_putchar_fd('-', 1);
	count++;
	count += ft_put_zeo(1);
	count += ft_put_strl(tmp + 1, tmp_len - 1);
	if (info->width > info->precision)
		count += ft_put_space(info->width - info->precision - 1);
	return (count);
}

int	ft_put_x(t_info_list *info, va_list ap)
{
	char	*tmp;
	int		tmp_len;
	int		count;

	tmp = ft_utoh(va_arg(ap, unsigned int));
	if (info->flag == 'X')
		tmp = to_str_upper(tmp);
	tmp_len = ft_strlen(tmp);
	if (info->has_precision != 0 && info->precision == 0 && *tmp == '0')
		count = ft_put_space(info->width);
	else if (info->precision > tmp_len)
	{
		if (info->has_minus == 1 && info->precision < info->width)
			count = mi_big_wid(tmp, tmp_len, info);
		else
			count = big_pre(tmp, tmp_len, info);
	}
	else if (tmp_len == info->precision && *tmp == '-')
		count = minus_ep(tmp, tmp_len, info);
	else if (info->has_minus == 1)
		count = else_m(tmp, tmp_len, info);
	else
		count = last_else(tmp, tmp_len, info);
	free(tmp);
	return (count);
}
