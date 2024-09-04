/* ************************************************************************** */
/*                                       /Users/mlakhdar/Desktop/c04/ex05/ft_atoi_base.c                                     */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlakhdar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:08:23 by mlakhdar          #+#    #+#             */
/*   Updated: 2024/08/12 10:49:54 by mlakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i +1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (0);
		i++;
	}
	return (1);
}

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	b_val(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	sign(char *s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	len_base;
	int	val;
	int	nichan;

	i = 0;
	if (len(base) < 2 || !check_base(base))
		return (0);
	sign = sign(str);
	len_base = len(base);
	nichan = 0;
	while (str[i])
	{
		val = b_val(base, str[i]);
		if (val == -1)
			return (0);
		nichan = nichan * len_base + val;
		i++;
	}
	return (nichan * res);
}
