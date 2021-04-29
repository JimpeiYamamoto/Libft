/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:13:14 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/19 23:40:46 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p_str;
	size_t	i;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!p_str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		p_str[i] = s[start];
		start++;
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}
