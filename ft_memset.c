/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:11:00 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/07 14:48:07 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		uc;
	unsigned char		*p;
	size_t				i;

	uc = c;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*p = uc;
		i++;
		p++;
	}
	return (s);
}
