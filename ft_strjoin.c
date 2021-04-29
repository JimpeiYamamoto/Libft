/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:37:49 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/14 13:46:16 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*p_str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	p_str = (char *)malloc(sizeof(char) * (size + 1));
	if (!p_str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		p_str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		p_str[i] = *s2;
		s2++;
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}
