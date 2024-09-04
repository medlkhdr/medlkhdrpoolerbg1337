/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:03:21 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/10 01:07:21 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_swap(char **s, char **i)
{
	char	*swap;

	swap = *s;
	*s = *i;
	*i = swap;
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (i < argc - 1)
	{
		k = i + 1;
		while (k < argc)
		{
			if (ft_strcmp(argv[i], argv[k]) > 0)
				ft_swap(&argv[i], &argv[k]);
			k++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
	}
	return (0);
}
