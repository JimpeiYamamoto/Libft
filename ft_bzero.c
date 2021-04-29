/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:33:13 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/07 14:45:36 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	uc;
	unsigned char	*p;
	size_t			i;

	uc = '\0';
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*p = uc;
		p++;
		i++;
	}
}
