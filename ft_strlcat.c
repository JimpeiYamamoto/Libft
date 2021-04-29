/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:04:37 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/13 00:33:42 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_size;
	size_t		src_size;
	size_t		res;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size < dst_size)
		res = src_size + size;
	else
		res = src_size + dst_size;
	i = 0;
	while (i + dst_size < size - 1 && src[i])
	{
		dst[i + dst_size] = src[i];
		i++;
	}
	dst[i + dst_size] = '\0';
	return (res);
}
