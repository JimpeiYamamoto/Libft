/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 22:44:24 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/14 23:12:58 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *list, void (*del)(void *))
{
	t_list	*tmp;

	if (!list)
		return ;
	tmp = list;
	if (!del)
		return ;
	del(tmp->content);
	free(tmp);
}
