/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 08:09:26 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/14 08:10:18 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdlib.h>

int    is_charset(char c, char *charset)
{
    int    i;

    i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return (1);
        i++;
    }
    return (0);
}

int    count_words(char *str, char *charset)
{
    int    i;
    int    count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && is_charset(str[i], charset))
            i++;
        if (str[i] && !is_charset(str[i], charset))
        {
            count++;
            while (str[i] && !is_charset(str[i], charset))
                i++;
        }
    }
    return (count);
}

char    *allocate(char *str, int start, int end)
{
    int        i;
    char    *word;

    i = 0;
    if (start >= end)
        return (NULL);
    word = (char *)malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str, char *charset)
{
    int        start;
    int        i;
    int        j;
    char    **tab;

    i = 0;
    j = 0;
    start = 0;
    tab = (char **)malloc((count_words(str, charset) + 1) * sizeof(char *));
    if (!tab)
        return (NULL);
    while (str[i])
    {
        while (str[i] && is_charset(str[i], charset))
            i++;
        start = i;
        while (str[i] && !is_charset(str[i], charset))
            i++;
        if (i > start)
            tab[j++] = allocate(str, start, i);
    }
    tab[j] = NULL;
    return (tab);
}
