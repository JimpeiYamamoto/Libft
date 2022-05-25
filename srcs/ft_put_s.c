/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:45:36 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:50:34 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_s(t_info_list *info, va_list ap)
{
	char	*tmp;
	int		tmp_len;
	int		count;

	tmp = va_arg(ap, char *);
	if (!tmp)
		tmp = "(null)";
	count = 0;
	tmp_len = ft_strlen(tmp);
	if (info->has_precision != 0 && info->precision < tmp_len)
		tmp_len = info->precision;
	if (info->has_width == 0 || (info->has_width != 0 && info->width < tmp_len))
		return (ft_put_strl(tmp, tmp_len));
	else if (info->width > tmp_len && info->has_minus != 0)
	{
		count += ft_put_strl(tmp, tmp_len);
		return (count + ft_put_space(info->width - tmp_len));
	}
	if (info->has_zero == 0)
		count += ft_put_space(info->width - tmp_len);
	else
		count += ft_put_zeo(info->width - tmp_len);
	return (count + ft_put_strl(tmp, tmp_len));
}
