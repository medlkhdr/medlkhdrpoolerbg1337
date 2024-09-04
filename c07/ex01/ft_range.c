/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:58:42 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/13 04:30:20 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	j;

	i = max - min;
	if (i <= 0)
	{
		return (NULL);
	}
	j = 0;
	tab = (int *)malloc(i * sizeof(int));
	if (!tab)
		return (NULL);
	while (j < i)
	{
		tab[j] = min + j;
		j++;
	}
	return (tab);
}
