/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:25:16 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/17 18:05:03 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char		*ft_word_add(char const *s, size_t *offset, char c)
{
	size_t	i;
	size_t	start;
	size_t	word_len;
	char	*dest;

	word_len = 0;
	while (s[*offset] && s[*offset] == c)
		*offset += 1;
	start = *offset;
	while (s[*offset] && s[*offset] != c)
	{
		*offset += 1;
		word_len++;
	}
	if (!(dest = malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void		ft_free(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	words;
	size_t	offset;
	char	**dest;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	if (!(dest = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	offset = 0;
	while (i < words)
	{
		if (!(dest[i] = ft_word_add(s, &offset, c)))
		{
			ft_free(dest);
			return (NULL);
		}
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
