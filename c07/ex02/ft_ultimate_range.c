/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:48:19 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/13 01:51:46 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = max - min;
	range[0] = (int *)malloc(i * sizeof(int));
	if (*range == NULL)
		return (-1);
	j = 0;
	while (j < i)
	{
		range[0][j] = min + j ;
		j++;
	}
	return (i);
}
