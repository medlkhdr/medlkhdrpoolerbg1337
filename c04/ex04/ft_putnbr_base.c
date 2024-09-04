/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 02:24:29 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/12 10:59:10 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base1(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

void	nichan(int counter, int *tab, char *base)
{
	while (counter >= 0)
	{
		write(1, &base[tab[counter]], 1);
		counter--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		a;
	int		tab[100];
	int		counter;
	long	n;

	n = nbr;
	a = len(base);
	counter = 0;
	if ((a < 2 || !check_base1(base)))
		return ;
	if (n == 0)
		write(1, &base[0], 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		tab[counter++] = n % a;
		n /= a;
	}
	nichan(counter - 1, tab, base);
}
