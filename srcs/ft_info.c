/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:01:09 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:28:44 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_info(t_info_list *info)
{
	info->flag = 0;
	info->has_zero = 0;
	info->has_minus = 0;
	info->width = 0;
	info->has_width = 0;
	info->precision = 0;
	info->has_precision = 0;
}

t_info_list	*get_info(char **form, t_info_list *info, va_list ap)
{
	init_info(info);
	if (*form == NULL || **form != '%')
		return (0);
	(*form)++;
	while (**form != '\0')
	{
		ft_form_before(form, info, ap);
		ft_form_after(form, info);
		if (ft_strchr("cspdiuxX%", **form))
		{
			info->flag = **form;
			(*form)++;
			if (info->has_width == 2)
				width_two(ap, info);
			if (info->has_precision == 2)
				prec_two(ap, info);
			return (info);
		}
		(*form)++;
	}
	return (info);
}
