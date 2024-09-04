/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:05:06 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/13 04:27:28 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
}

char	*ft_allocate(int size, char **strs, char *sep)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < size)
	{
		n = n + len(strs[i]);
		i++;
	}
	n += len(sep) * (size - 1) + 1;
	return ((char *)malloc(n * sizeof(char)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;

	tab = ft_allocate(size, strs, sep);
	if (tab == NULL)
		return (NULL);
	if (size == 0)
	{
		tab = (char *)malloc(1 * sizeof(char));
		tab[0] = '\0';
	}
	tab[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(tab, strs[i]);
		if (i < size - 1)
			ft_strcat(tab, sep);
		i++;
	}
	return (tab);
}
