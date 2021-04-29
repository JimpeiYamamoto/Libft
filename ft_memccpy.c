/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:09:13 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/17 14:55:33 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;
	unsigned char	uc;
	size_t			i;

	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	uc = (unsigned char)c;
	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n && uc != p_src[i])
	{
		p_dest[i] = p_src[i];
		i++;
	}
	if (i == n)
		return (NULL);
	p_dest[i] = p_src[i];
	return (dest + i + 1);
}
