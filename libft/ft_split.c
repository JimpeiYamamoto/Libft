/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:37:52 by yjimpei           #+#    #+#             */
/*   Updated: 2021/04/27 02:04:59 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	word_count(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			count++;
			while (*s && *s == c)
				s++;
		}
		else
			s++;
	}
	if (*(s - 1) && *(s - 1) != c)
		count++;
	return (count);
}

static void	get_next_str(char **tmp, unsigned int *tmp_len, char c)
{
	unsigned int	i;

	*tmp += *tmp_len;
	*tmp_len = 0;
	i = 0;
	while (**tmp && **tmp == c)
		(*tmp)++;
	while ((*tmp)[i])
	{
		if ((*tmp)[i] == c)
			return ;
		(*tmp_len)++;
		i++;
	}
}

static char	**free_str(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static char	**make_split(char **str, const char *s, char c)
{
	unsigned int	i;
	char			*tmp;
	unsigned int	tmp_len;
	unsigned int	count;

	i = 0;
	tmp = (char *)s;
	tmp_len = 0;
	count = word_count(s, c);
	while (i < count)
	{
		get_next_str(&tmp, &tmp_len, c);
		str[i] = (char *)malloc(sizeof(char) * (tmp_len + 1));
		if (!str[i])
			return (free_str(str));
		ft_strlcpy(str[i], tmp, tmp_len + 1);
		i++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char			**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!str)
		return (str);
	return (make_split(str, s, c));
}
