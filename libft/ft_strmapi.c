/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 18:23:38 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/14 22:19:51 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	p_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p_str[i] = f(i, s[i]);
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}
