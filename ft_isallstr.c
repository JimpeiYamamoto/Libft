/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isallstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:50:01 by yjimpei           #+#    #+#             */
/*   Updated: 2022/04/24 16:50:22 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isallstr(char *str, int(f)(char))
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (f(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
