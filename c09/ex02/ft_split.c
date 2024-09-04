/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 04:53:00 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/15 07:00:01 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset++)
			return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_charset(*str, charset))
			str++;
		if (*str && !is_charset(*str, charset))
		{
			count++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*allocate_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char		**tab;
	int			i;
	int			k;
	int			w;
	int			j;

	i = 0;
	k = 0;
	j = 0;
	w = count_words(str, charset);
	tab = (char **)malloc((w + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab[w] = NULL;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		k = i;
		while (str[i] && !is_charset(str[i], charset))
			i++;
		if (i > k)
			tab[j++] = allocate_word(str, k, i);
	}
	return (tab);
}
