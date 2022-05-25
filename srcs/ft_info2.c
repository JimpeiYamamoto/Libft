/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 18:09:43 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:29:26 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	width_two(va_list ap, t_info_list *info)
{
	long	star;

	star = va_arg(ap, int);
	if (star < 0 && info->has_minus != 0)
	{
		star *= -1;
		info->has_minus = 1;
		info->has_zero = 0;
	}
	else if (star < 0)
	{
		star *= -1;
		info->has_minus = 1;
		info->has_zero = 0;
	}
	info->width = star;
}

void	prec_two(va_list ap, t_info_list *info)
{
	long	star;

	star = va_arg(ap, int);
	if (star < 0)
	{
		star = 0;
		info->has_precision = 0;
	}
	info->precision = star;
}

void	ft_form_digit(va_list ap, char **form, t_info_list *info)
{
	while (**form == '0')
	{
		if (info->has_zero != -1)
			info->has_zero = 1;
		(*form)++;
	}
	if (**form == '*')
	{
		while (**form == '*')
			(*form)++;
		info->has_width = 2;
	}
	if (ft_isdigit(**form))
	{
		if (info->has_width == 2)
			va_arg(ap, int);
		info->has_width = 1;
		info->width = ft_atoi(*form);
		(*form) += ft_get_digit(info->width);
	}
}

void	ft_form_before(char **form, t_info_list *info, va_list ap)
{
	if (**form == '*')
	{
		while (**form == '*')
			(*form)++;
		info->has_width = 2;
	}
	if (**form == '-')
	{
		info->has_minus = 1;
		info->has_zero = -1;
	}
	if (ft_isdigit(**form))
		ft_form_digit(ap, form, info);
	if (**form == '.')
	{
		info->has_precision = 1;
		(*form)++;
	}
	if (**form == '*')
	{
		while (**form == '*')
			(*form)++;
		info->has_precision = 2;
	}
}

void	ft_form_after(char **form, t_info_list *info)
{
	if (ft_isdigit(**form))
	{
		info->has_precision = 1;
		info->precision = ft_atoi(*form);
		(*form) += ft_get_digit(info->precision);
	}
	if (**form == '-')
	{
		info->has_minus = 1;
		info->has_zero = -1;
	}
}
