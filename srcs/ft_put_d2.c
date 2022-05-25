/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:03:50 by yjimpei           #+#    #+#             */
/*   Updated: 2021/05/22 21:29:48 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	d_last_else_m(int count, t_info_list *info, char *tmp, int tmp_len)
{
	count = ft_put_strl(tmp, tmp_len);
	if (info->width > tmp_len)
		count += ft_put_space(info->width - tmp_len);
	return (count);
}
