/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:54:51 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/12 23:14:44 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*p_s;

	p_s = (char *)s;
	size = ft_strlen(s);
	while (size > 0)
	{
		if (p_s[size] == (char)c)
			return (&p_s[size]);
		size--;
	}
	if (p_s[0] == (char)c)
		return (p_s);
	return (NULL);
}
