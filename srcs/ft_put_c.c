/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:40:37 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/28 00:47:06 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	no_tmp(t_info_list *info)
{
	int	count;

	count = 0;
	if (info->has_width != 0 && info->has_minus != 0)
	{
		ft_putchar_fd('\x00', 1);
		count++;
		count += ft_put_space(info->width - 1);
	}
	else if (info->has_width != 0 && info->has_minus == 0)
	{
		count += ft_put_space(info->width - 1);
		ft_putchar_fd('\x00', 1);
		count++;
	}
	else
	{
		ft_putchar_fd('\x00', 1);
		count++;
	}
	return (count);
}

static int	else_info(t_info_list *info, unsigned char tmp, int tmp_len)
{
	int	count;

	count = 0;
	if (info->has_zero == 0)
	{
		count += ft_put_space(info->width - tmp_len);
		ft_putchar_fd((char)tmp, 1);
		count++;
	}
	else
	{
		count += ft_put_zeo(info->width - tmp_len);
		ft_putchar_fd((char)tmp, 1);
		count++;
	}
	return (count);
}

static int	else_if_info(t_info_list *info, unsigned char tmp, int tmp_len)
{
	int	count;

	count = 0;
	if (info->has_zero == 0)
	{
		ft_putchar_fd((char)tmp, 1);
		count++;
		count += ft_put_space(info->width - tmp_len);
	}
	else
	{
		ft_putchar_fd((char)tmp, 1);
		count++;
		count += ft_put_space(info->width - tmp_len);
	}
	return (count);
}

int	ft_put_c(t_info_list *info, va_list ap)
{
	unsigned char	tmp;
	int				tmp_len;
	int				count;

	count = 0;
	if (info->flag == '%')
		tmp = '%';
	else
		tmp = va_arg(ap, unsigned int);
	if (!tmp)
		return (no_tmp(info));
	tmp_len = 1;
	if (info->has_precision && info->precision < tmp_len && info->precision)
		tmp_len = info->precision;
	if (info->has_width == 0 || (info->has_width != 0 && info->width < tmp_len))
	{
		ft_putchar_fd((char)tmp, 1);
		count++;
		return (count);
	}
	else if (info->width > tmp_len && info->has_minus != 0)
		return (else_if_info(info, tmp, tmp_len));
	return (else_info(info, tmp, tmp_len));
}
