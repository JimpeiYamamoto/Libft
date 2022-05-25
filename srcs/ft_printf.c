/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:24:11 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:29:31 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_conv(t_info_list *info, va_list ap)
{
	if (info->flag == 's')
		return (ft_put_s(info, ap));
	if (info->flag == 'd' || info->flag == 'i')
		return (ft_put_d(info, ap));
	if (info->flag == 'c' || info->flag == '%')
		return (ft_put_c(info, ap));
	if (info->flag == 'u')
		return (ft_put_u(info, ap));
	if (info->flag == 'x' || info->flag == 'X')
		return (ft_put_x(info, ap));
	if (info->flag == 'p')
		return (ft_put_p(info, ap));
	return (1);
}

static int	ft_loop(char *form, va_list ap, int count)
{
	t_info_list	info;

	while (*form != '\0')
	{
		if (*form == '%')
		{
			get_info(&form, &info, ap);
			if (info.flag == 0)
				return (-1);
			count += ft_put_conv(&info, ap);
			if (*form == '\0')
				return (count);
		}
		if (*form != '%')
		{
			ft_putchar_fd(*form, 1);
			form++;
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*form;
	int			count;

	va_start(ap, format);
	form = (char *)format;
	count = 0;
	count = ft_loop(form, ap, count);
	va_end(ap);
	return (count);
}
